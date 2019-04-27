CC = g++

GAME_VERSION = $(shell cat ../../__REVISION__)

INCDIR =
LIBDIR =
BINDIR = ..
OBJDIR = OBJDIR_GAME
SRV_DIR = /usr/game
$(shell if [ ! -d $(OBJDIR) ]; then mkdir $(OBJDIR); fi)

# Project Flags
CFLAGS = -g -Wall -O2 -w -m32 -pipe -fexceptions -D_THREAD_SAFE -DNDEBUG

# Version Defines
CFLAGS += -D__USER__=\"$(USER)\" -D__HOSTNAME__=\"$(HOSTNAME)\" -D__PWD__=\"$(PWD)\" -D__GAME_VERSION__=\"$(GAME_VERSION)\"

# Project Library
INCDIR += -I../../../Extern/include
INCDIR += -I../../../Extern/include/mysql
INCDIR += -I../../../Extern/include/devil
INCDIR += -I../../../Extern/include/boost
INCDIR += -I../../../Extern/include/liblua
LIBDIR += -L../../../Extern/lib
LIBDIR += -L../../libthecore/lib -L../../libpoly -L../../libsql -L../../libgame/lib -L../../liblua/lib
LIBS += -lthecore -lpoly -llua -llualib -lsql -lgame -lssl -lcryptopp -lmysqlclient -lz -lIL -lpng -ltiff -lmng -llcms -ljpeg -pthread -lm -lmd

CFILE	= minilzo.c

CPPFILE = BattleArena.cpp FSM.cpp MarkConvert.cpp MarkImage.cpp MarkManager.cpp OXEvent.cpp TrafficProfiler.cpp ani.cpp\
		  arena.cpp banword.cpp battle.cpp blend_item.cpp block_country.cpp buffer_manager.cpp building.cpp castle.cpp\
		  char.cpp char_affect.cpp char_battle.cpp char_cards.cpp char_change_empire.cpp char_horse.cpp char_item.cpp char_manager.cpp\
		  char_quickslot.cpp char_resist.cpp char_skill.cpp char_state.cpp PetSystem.cpp cmd.cpp cmd_emotion.cpp cmd_general.cpp\
		  cmd_gm.cpp cmd_oxevent.cpp config.cpp constants.cpp crc32.cpp cube.cpp db.cpp desc.cpp\
		  desc_client.cpp desc_manager.cpp desc_p2p.cpp dev_log.cpp dungeon.cpp empire_text_convert.cpp entity.cpp\
		  entity_view.cpp event.cpp event_queue.cpp exchange.cpp file_loader.cpp fishing.cpp gm.cpp guild.cpp\
		  guild_manager.cpp guild_war.cpp horse_rider.cpp horsename_manager.cpp input.cpp input_auth.cpp input_db.cpp\
		  input_login.cpp input_main.cpp input_p2p.cpp input_teen.cpp input_udp.cpp ip_ban.cpp\
		  item.cpp item_addon.cpp item_attribute.cpp item_manager.cpp item_manager_idrange.cpp locale.cpp\
		  locale_service.cpp log.cpp login_data.cpp lzo_manager.cpp marriage.cpp matrix_card.cpp\
		  messenger_manager.cpp mining.cpp mob_manager.cpp monarch.cpp motion.cpp over9refine.cpp p2p.cpp packet_info.cpp\
		  party.cpp passpod.cpp pcbang.cpp polymorph.cpp priv_manager.cpp pvp.cpp\
		  questevent.cpp questlua.cpp questlua_affect.cpp questlua_arena.cpp questlua_ba.cpp questlua_building.cpp\
		  questlua_danceevent.cpp questlua_dungeon.cpp questlua_forked.cpp questlua_game.cpp questlua_global.cpp\
		  questlua_guild.cpp questlua_horse.cpp questlua_pet.cpp questlua_item.cpp questlua_marriage.cpp questlua_mgmt.cpp\
		  questlua_monarch.cpp questlua_npc.cpp questlua_oxevent.cpp questlua_party.cpp questlua_pc.cpp\
		  questlua_quest.cpp questlua_target.cpp questmanager.cpp questnpc.cpp questpc.cpp\
		  refine.cpp regen.cpp safebox.cpp sectree.cpp sectree_manager.cpp sequence.cpp shop.cpp\
		  skill.cpp start_position.cpp target.cpp text_file_loader.cpp trigger.cpp utils.cpp vector.cpp war_map.cpp\
		  wedding.cpp xmas_event.cpp version.cpp panama.cpp threeway_war.cpp map_location.cpp auth_brazil.cpp\
		  BlueDragon.cpp BlueDragon_Binder.cpp DragonLair.cpp questlua_dragonlair.cpp skill_power.cpp affect.cpp\
		  SpeedServer.cpp questlua_speedserver.cpp auction_manager.cpp buff_on_attributes.cpp\
		  FileMonitor_FreeBSD.cpp ClientPackageCryptInfo.cpp cipher.cpp dragon_soul_table.cpp\
		  group_text_parse_tree.cpp char_dragonsoul.cpp questlua_dragonsoul.cpp DragonSoul.cpp\
		  shop_manager.cpp shopEx.cpp item_manager_read_tables.cpp attr_transfer.cpp New_PetSystem.cpp questlua_petnew.cpp\
		  offline_shop.cpp offlineshop_manager.cpp offlineshop_config.cpp TempleOchao.cpp questlua_TempleOchao.cpp MeleyLair.cpp questlua_MeleyLair.cpp 

COBJS	= $(CFILE:%.c=$(OBJDIR)/%.o)
CPPOBJS	= $(CPPFILE:%.cpp=$(OBJDIR)/%.o)

MAINOBJ = $(OBJDIR)/main.o
MAINCPP = main.cpp

TARGET  = $(BINDIR)/game_r$(GAME_VERSION)

default: $(TARGET)

$(OBJDIR)/minilzo.o: minilzo.c
	@echo -e "\033[0;32mCompilazione ->\033[0m" $<
	@$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

$(OBJDIR)/%.o: %.cpp
	@echo -e "\033[0;32mCompilazione ->\033[0m" $<
	@$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

$(TARGET): $(CPPOBJS) $(COBJS) $(MAINOBJ)
	@echo -e "\033[0;33mCreazione file game ->\033[0m" $(TARGET)
	@$(CC) $(CFLAGS) $(LIBDIR) $(COBJS) $(CPPOBJS) $(MAINOBJ) $(LIBS) -o $(TARGET)

symlink:
	@ln -fs game_r$(GAME_VERSION) $(BINDIR)/game_symlink

strip:
	@cp $(BINDIR)/game_r$(GAME_VERSION) $(BINDIR)/game_r
	@strip $(BINDIR)/game_r

clean:
	@rm -f OBJDIR_GAME/*
	@rm -f $(BINDIR)/game_r* $(BINDIR)/conv

tag:
	ctags *.cpp *.h *.c

install: $(DTARGET)
	rm -rf $(SRV_DIR)/share/bin/game
	cp $(TARGET) $(SRV_DIR)/share/bin/game

dep:
	makedepend -f Depend $(INCDIR) -I/usr/include/c++/v1 -I/usr/include/c++/v1 -p$(OBJDIR)/ $(CPPFILE) $(CFILE) $(MAINCPP) 2> /dev/null > Depend

sinclude Depend
