# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	data
PORTVERSION=	0.21.1
CATEGORIES=	games
MASTER_SITES=	SF/scourge/scourge/${PORTVERSION}
PKGNAMEPREFIX=	scourge-
DISTNAME=	${PKGNAMEPREFIX}${PORTVERSION}${PORTNAME:S/^/./}
DIST_SUBDIR=	${PKGNAMEPREFIX:S/-//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	S.C.O.U.R.G.E data files

NO_BUILD=	yes

DATADIR=	share/${PKGNAMEPREFIX:S/-//}
PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX:S/-/_/}${PORTNAME}

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC} && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
			${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm %%DATADIR%%/|' >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%" >> ${PLIST}

do-install:
	@cd ${WRKSRC} && \
		${MKDIR} ${STAGEDIR}${PREFIX}/${DATADIR} && \
			${CP} -R * ${STAGEDIR}${PREFIX}/${DATADIR}
	@cd ${STAGEDIR}${PREFIX}/${DATADIR} && \
		${FIND} * -type f -print0 | ${XARGS} -0 ${CHMOD} ${SHAREMODE}

.include <bsd.port.mk>
