# Created by: bsam
# $FreeBSD$

PORTNAME=	cairo
PORTVERSION=	1.8.0
PORTREVISION=	2
CATEGORIES=	graphics linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Vector graphics library Cairo (Linux Fedora 10)

CONFLICTS=	linux-cairo-[0-9]* linux-f8-cairo-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	fontconfig png xorglibs
LINUX_DIST_VER=	10
RPMVERSION=	1.fc10
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libcairo.so.2 \
		usr/lib/libcairo.so.2.10800.0
DOCSDIR=	${PREFIX}/usr/share/doc/cairo-${PORTVERSION}
PORTDOCS=	AUTHORS BIBLIOGRAPHY BUGS COPYING COPYING-LGPL-2.1 \
		COPYING-MPL-1.1 ChangeLog NEWS PORTING_GUIDE README

.include <bsd.port.mk>
