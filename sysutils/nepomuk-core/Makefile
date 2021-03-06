# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nepomuk-core
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	sysutils kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Core Nepomuk system libraries and services for KDE

LIB_DEPENDS=	libpoppler-qt4.so:${PORTSDIR}/graphics/poppler-qt4 \
		libtag.so:${PORTSDIR}/audio/taglib \
		libexiv2.so:${PORTSDIR}/graphics/exiv2 \
		libswscale.so:${PORTSDIR}/multimedia/ffmpeg \
		libepub.so:${PORTSDIR}/textproc/ebook-tools \
		libqmobipocket.so:${PORTSDIR}/graphics/kdegraphics4-mobipocket

USE_KDE4=	kdeprefix kdehier automoc4 kdelibs ontologies soprano
USES=		cmake:outsource tar:xz
USE_QT4=	corelib dbus gui qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes
MAKE_ENV=	XDG_CONFIG_HOME=/dev/null

SUB_FILES=	nepomuk-env.sh

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/env
	${INSTALL_SCRIPT} ${WRKDIR}/nepomuk-env.sh ${STAGEDIR}${PREFIX}/env

.include <bsd.port.mk>
