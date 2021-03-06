# Created by: David Taylor <davidt@yadt.co.uk>
# $FreeBSD$

PORTNAME=	ircd-hybrid
PORTVERSION=	8.1.3
PORTREVISION=	1
CATEGORIES=	irc ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	db@FreeBSD.org
COMMENT=	Fast irc daemon with a number of new features

INSTALL_IGNORES=	ircu-* ircd-rat* charby*

# :keepla because port uses lt_dlopen
USES=		gmake libtool:keepla tar:tgz
GNU_CONFIGURE=	yes

USERS=		ircd
GROUPS=		${USERS}

USE_RC_SUBR=	ircd-hybrid
SUB_FILES=	pkg-message
PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	OPENSSL HALFOPS ASSERT
OPTIONS_DEFAULT=OPENSSL

ASSERT_CONFIGURE_ENABLE=	assert
ASSERT_DESC=	Enable parts of the debugging code

HALFOPS_CONFIGURE_ENABLE=	halfops
HALFOPS_DESC=	Enable halfops on the server

OPENSSL_DESC=	Enable openssl - allows use of CHALLENGE and encrypted links

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--enable-openssl=${OPENSSLBASE}
.endif

# User Configurable Variables
# NICKLEN		- Nick length. Default is 9. Must be consistent across the network.

.if defined(NICKLEN)
CONFIGURE_ARGS+=	--with-nicklen=${NICKLEN}
.endif

CONFIGURE_ARGS+=	\
	--sysconfdir=${PREFIX}/etc/ircd-hybrid \
	--datarootdir=${PREFIX}/share/${PORTNAME}-${PORTVERSION} \
	--localstatedir=/var

.include <bsd.port.mk>
