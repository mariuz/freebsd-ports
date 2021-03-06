# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	atutor
PORTVERSION=	2.1.1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/ATutor%202/
DISTNAME=	ATutor-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Open Source Web-based Learning Content Management System (LCMS)

USE_PHP=	session mbstring zlib mysql
WRKSRC=		${WRKDIR}/ATutor

.include <bsd.port.pre.mk>

NO_BUILD=	yes
PLIST=		${WRKDIR}/plist
SUB_FILES=	pkg-message

ATUTDIR=	www/atutor
ATUTDATDIR=	${WWWDIR}/content
ATUTCONFIG=	include/config.inc.php

pre-install:
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${ATUTDIR}?g" >${PLIST}
	@${ECHO} @dirrm ${ATUTDIR}/content >> ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s?${WRKSRC}?@dirrm ${ATUTDIR}?g" >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${WWWDIR}' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${WWWDIR} -type d -exec ${CHMOD} a+x {} \;
	@${INSTALL_DATA} -d ${STAGEDIR}${ATUTDATDIR}
	@${CHMOD} 777 ${STAGEDIR}${ATUTDATDIR}
	@${ECHO_CMD} '@exec ${CHMOD} 777 ${ATUTDATDIR}' >> ${TMPPLIST}
	@${CHMOD} 666 ${STAGEDIR}${WWWDIR}/${ATUTCONFIG}
	@${ECHO_CMD} '@exec ${CHMOD} 666 \
		${WWWDIR}/${ATUTCONFIG}' >> ${TMPPLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
