## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = smart

smart_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	capteur.c capteur.h \
	etudiant.c etudiant.h \
	fonction.c fonction.h \
	email.c email.h \
	users.c users.h \
	stock_ahmed.c stock_ahmed.h \
	menufct.c menufct.h \
	etudiant1.c etudiant1.h

smart_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

