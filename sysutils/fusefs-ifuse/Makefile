# Created by: Gabor Zahemszky
# $FreeBSD$

PORTNAME=	ifuse
PORTVERSION=	1.1.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.libimobiledevice.org/downloads/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	FUSE-based filesystem for mounting iOS devices over USB

LICENSE=	LGPL21

LIB_DEPENDS=	libplist.so:${PORTSDIR}/devel/libplist \
		libimobiledevice.so:${PORTSDIR}/comms/libimobiledevice
RUN_DEPENDS=	usbmuxd:${PORTSDIR}/comms/usbmuxd

USE_GNOME=	glib20
USES=		fuse pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME} man/man1/ifuse.1.gz

.include <bsd.port.mk>
