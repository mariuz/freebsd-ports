# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ultracopier
PORTVERSION=	0.2.0.16
PORTREVISION=	6
CATEGORIES=	x11-fm kde
MASTER_SITES=	http://files.first-world.info/ultracopier/${PORTVERSION}/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced file copier

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USE_KDE4=	automoc4 kdelibs
USE_QT4=	corelib dbus gui moc_build network qmake_build rcc_build svg \
		uic_build xml xmlpatterns

USES=		cmake desktop-file-utils tar:bzip2
CMAKE_ARGS+=	-DCMAKE_BUILD_KDE4:bool=true
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR_WITHOUT_PREFIX:Q} \
		ICONS_DIR=${ICONS_DIR:Q}

DESKTOPDIR_WITHOUT_PREFIX=	${DESKTOPDIR:S,^${PREFIX}/,,}
ICONS_DIR=	share/icons/hicolor

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|0\.2\.0\.15|0.2.0.16|; \
		s|0,2,0,15|0,2,0,16|' \
		${WRKSRC}/src/var.h

post-install:
# install icons
.for dimensions in 16x16 128x128
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${dimensions}/apps
	@${INSTALL_DATA} ${WRKSRC}/src/other/ultracopier-${dimensions}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${dimensions}/apps/ultracopier.png
.endfor
# install desktop file
	@${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	@${INSTALL_DATA} ${WRKSRC}/src/other/ultracopier.desktop \
		${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
