# $FreeBSD$

PORTNAME=	beadm
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	GH \
		http://mirror.shatow.net/freebsd/${PORTNAME}/ \
		LOCAL/bdrewery/${PORTNAME}

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Solaris-like utility to manage Boot Environments on ZFS

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	vermaden
GH_COMMIT=	748d2f2
GH_TAGNAME=	${GH_COMMIT}

NO_BUILD=	YES

CONFLICTS_INSTALL=	beadm-devel-*

PLIST_FILES=	sbin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} \
	    ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
	  ${STAGEDIR}${MANPREFIX}/man/man1/

.include <bsd.port.mk>
