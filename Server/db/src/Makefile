CC = g++

DB_VERSION = $(shell cat ../../__REVISION__)

INCDIR =
LIBDIR =
BINDIR = ..
OBJDIR = OBJDIR_DB
SRV_DIR = /usr/game
$(shell if [ ! -d $(OBJDIR) ]; then mkdir $(OBJDIR); fi)

# Project Flags
CFLAGS = -g -Wall -O2 -w -pipe -fno-rtti -fno-exceptions -pthread -D_THREAD_SAFE

# Version defines
CFLAGS += -D__USER__=\"$(USER)\" -D__HOSTNAME__=\"$(HOSTNAME)\" -D__PWD__=\"$(PWD)\" -D__DB_VERSION__=\"$(DB_VERSION)\"

# Project Library
LIBDIR += -L../../../Extern/lib
INCDIR += -I../../../Extern/include
INCDIR += -I../../../Extern/include/mysql
LIBDIR += -L../../libthecore/lib -L../../libsql -L../../libpoly -L../../libgame/lib
LIBS = -lthecore -lmysqlclient -lsql -lpoly -lgame -lm -lz

SRCS =	Config.cpp NetBase.cpp Peer.cpp PeerBase.cpp Main.cpp Lock.cpp DBManager.cpp \
		Cache.cpp LoginData.cpp ClientManager.cpp ClientManagerPlayer.cpp ClientManagerLogin.cpp \
		ClientManagerBoot.cpp ClientManagerParty.cpp ClientManagerGuild.cpp GuildManager.cpp HB.cpp \
		PrivManager.cpp MoneyLog.cpp ItemAwardManager.cpp ClientManagerEventFlag.cpp Marriage.cpp \
		Monarch.cpp BlockCountry.cpp ItemIDRangeManager.cpp ClientManagerHorseName.cpp version.cpp \
		AuctionManager.cpp ProtoReader.cpp CsvReader.cpp 

OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

TARGET = $(BINDIR)/db_r$(DB_VERSION)

default: $(TARGET)

$(TARGET): $(OBJS)
	@echo -e "\033[0;33mDatabase compilato ->\033[0m" $(TARGET)
	@$(CC) $(CFLAGS) $(LIBDIR) $(OBJS) $(LIBS) -o $(TARGET)

$(OBJDIR)/%.o: %.cpp
	@echo -e "\033[0;32mCompilazione ->\033[0m" $<
	@$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

$(OBJDIR):
	@mkdir $(OBJDIR)

symlink:
	@ln -fs db_r$(DB_VERSION) $(BINDIR)/db_symlink

strip:
	@cp $(BINDIR)/db_r$(DB_VERSION) $(BINDIR)/db_r
	@strip $(BINDIR)/db_r

clean:
	@rm -f OBJDIR_DB/*
	@rm -f $(BINDIR)/db_r* $(BINDIR)/conv

install: $(TARGET)
	rm -rf $(SRV_DIR)/share/bin/db
	cp $(TARGET) $(SRV_DIR)/share/bin/db

dep:
	@touch Depend
	makedepend -f Depend $(INCDIR) -I/usr/include/c++/v1 -I/usr/include/c++/v1 -p$(OBJDIR)/ $(SRCS) 2> /dev/null

sinclude Depend
