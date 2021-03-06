# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	m17n-lib
PORTVERSION=	1.6.4
PORTREVISION=	5
CATEGORIES=	devel textproc
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	m17n

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	Library for the multilingual text handling

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison \
		m17n-db>=1.6.4:${PORTSDIR}/devel/m17n-db
LIB_DEPENDS=	libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfribidi.so:${PORTSDIR}/converters/fribidi \
		libgd.so:${PORTSDIR}/graphics/gd \
		libotf.so:${PORTSDIR}/print/libotf
RUN_DEPENDS=	m17n-db>=1.6.4:${PORTSDIR}/devel/m17n-db

MAKE_JOBS_UNSAFE=	yes

USES=		pkgconfig libtool:oldver
USE_XORG=	ice sm x11 xaw xft xt
USE_GNOME=	libxml2
USE_AUTOTOOLS=	autoconf
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-nls

OPTIONS_DEFINE=	ANTHY ISPELL THAI

ANTHY_DESC=	Kana-Kanji conversion support via Anthy
ISPELL_DESC=	Spell checking support via Ispell
THAI_DESC=	Thai language support via libThai

ANTHY_LIB_DEPENDS=	libanthy.so:${PORTSDIR}/japanese/anthy
ANTHY_CONFIGURE_OFF+=	--without-anthy

ISPELL_BUILD_DEPENDS=	ispell:${PORTSDIR}/textproc/aspell-ispell
ISPELL_RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/aspell-ispell
ISPELL_CONFIGURE_OFF=	HAVE_ISPELL=no

THAI_LIB_DEPENDS=	libthai.so:${PORTSDIR}/devel/libthai
THAI_CONFIGURE_OFF=	--without-libthai

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$${libdir}/pkgconfig|$${prefix}/libdata/pkgconfig|g ; \
		 s|-ldl||g'

.include <bsd.port.mk>
