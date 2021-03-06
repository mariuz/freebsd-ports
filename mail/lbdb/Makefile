# Created by: mwest@uct.ac.za
# $FreeBSD$

PORTNAME=	lbdb
PORTVERSION=	0.39
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.spinnaker.de/debian/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Tools for use with mutt external mail address query feature

RUN_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed

OPTIONS_DEFINE=	ABOOK EVOLUTION GPG LDAP
ABOOK_DESC=	abook address book support
EVOLUTION_DESC=	Ximan Evolution support
GPG_DESC=	GNU Privacy Guard support

WRKSRC=		${WRKDIR}/lbdb-${PORTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-lbdb-dotlock \
		--libdir=${PREFIX}/libexec/lbdb
MAKE_ARGS=	install_prefix=${STAGEDIR}
USES=		gmake perl5

.include <bsd.port.options.mk>

.if exists (/usr/bin/getent)
WITH_GETENT=	yes
.endif

.if ${PORT_OPTIONS:MGPG}
BUILD_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg
RUN_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg
PLIST_SUB+=	GPG=""
.else
PLIST_SUB+=	GPG="@comment "
.endif

.if ${PORT_OPTIONS:MABOOK}
BUILD_DEPENDS+=	abook:${PORTSDIR}/mail/abook
RUN_DEPENDS+=	abook:${PORTSDIR}/mail/abook
PLIST_SUB+=	ABOOK=""
.else
PLIST_SUB+=	ABOOK="@comment "
.endif

.if ${PORT_OPTIONS:MEVOLUTION}
BUILD_DEPENDS+=	evolution:${PORTSDIR}/mail/evolution
RUN_DEPENDS+=	evolution:${PORTSDIR}/mail/evolution
PLIST_SUB+=	EVOLUTION=""
.else
PLIST_SUB+=	EVOLUTION="@comment "
.endif

.if ${PORT_OPTIONS:MGETENT}
PLIST_SUB+=	GETENT=""
.else
PLIST_SUB+=	GETENT="@comment "
.endif

.if ${PORT_OPTIONS:MLDAP}
RUN_DEPENDS+=	p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap
.endif

post-patch:
	${REINPLACE_CMD} -e 's/sed/gsed/' ${WRKSRC}/m_muttalias.sh.in

.include <bsd.port.mk>
