# Created by: Jaap Akkerhuis <jaap@NLnetLabs.nl>
# $FreeBSD$

PORTNAME=	softhsm
PORTVERSION=	1.3.7
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://dist.opendnssec.org/source/

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Software implementation of a Hardware Security Module (HSM)

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libbotan-1.10.so:${PORTSDIR}/security/botan110 \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-botan=${LOCALBASE} --with-sqlite3=${LOCALBASE} \
		--localstatedir=/var
INSTALL_TARGET=	install-strip
USES=		libtool
USE_LDCONFIG=	yes

.include <bsd.port.mk>
