# Created by: kris@FreeBSD.org
# $FreeBSD$

PORTNAME=	fortran-utils
PORTVERSION=	1.1
CATEGORIES=	devel
MASTER_SITES=	LOCAL
MASTER_SITE_SUBDIR=	kris

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools for use with Fortran code, from 4.4BSD

WRKSRC=		${WRKDIR}/fortran-utils

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fpr/fpr ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fsplit/fsplit ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fpr/fpr.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/fsplit/fsplit.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
