# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	winefish
DISTVERSION=	1.3.3
PORTREVISION=	14
CATEGORIES=	editors print
MASTER_SITES=	http://download.berlios.de/winefish/ \
		http://nivi.interfree.it/distfiles/winefish/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LaTeX editor based on BlueFish

LICENSE=	GPLv2

LIB_DEPENDS=	libaspell.so:${PORTSDIR}/textproc/aspell \
		libpcre.so:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	dos2unix:${PORTSDIR}/converters/unix2dos \
		gv:${PORTSDIR}/print/gv \
		tidy:${PORTSDIR}/www/tidy-lib \
		xpdf:${PORTSDIR}/graphics/xpdf

CONFIGURE_ARGS+=	--with-freedesktop_org-menu=${GNOME_LOCALSTATEDIR}/applications --with-icon-path=${GNOME_LOCALSTATEDIR}/pixmaps
GNU_CONFIGURE=	yes
USES=		gmake pkgconfig desktop-file-utils shared-mime-info
USE_GNOME=	libgnomeui desktopfileutils gnomehier
USE_TEX=	latex

OPTIONS_DEFINE=	CONTEXT VNTEX UNIKEY_GTK NLS DOCS
CONTEXT_DESC=		ConTexT support (Experimental)
VNTEX_DESC=		Vietnamese TeX user
UNIKEY_GTK_DESC=	Vietname Tex user with UnikeyGTK input method
CONTEXT_CONFIGURE_WITH=	context

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=	gettext
PLIST_SUB=	IFNLS=
# vietnamese support
.if ${PORT_OPTIONS:MUNIKEY_GTK} && !${PORT_OPTIONS:MVNTEX}
PORT_OPTIONS+=	VNTEX
.endif

.if ${PORT_OPTIONS:MVNTEX}
CONFIGURE_ARGS+=	--with-vntex
.if ${PORT_OPTIONS:MUNIKEY_GTK}
CONFIGURE_ARGS+=	--with-unikey-gtk
.endif
.endif
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=	IFNLS="@comment "
.endif

.include <bsd.port.mk>
