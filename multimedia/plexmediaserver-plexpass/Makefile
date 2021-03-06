# Created by: KalleDK <plexmaintainer@k-moeller.dk>
# $FreeBSD$

PORTNAME=	plexmediaserver
PORTVERSION=	0.9.9.16.555
CATEGORIES=	multimedia
MASTER_SITES=	http://downloads.plexapp.com/plex-media-server/${PORTVERSION}-${PLEX_BUILD}/
PKGNAMESUFFIX=	-plexpass
DISTNAME=	PlexMediaServer-${PORTVERSION}-${PLEX_BUILD}-freebsd-amd64

MAINTAINER=	feld@FreeBSD.org
COMMENT=	The Plex Media Server component

USES=		tar:bzip2
PLEX_BUILD=	50cd0c3
NO_BUILD=	yes
WRKSRC=	${WRKDIR}/PlexMediaServer-${PORTVERSION}-${PLEX_BUILD}

DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}

USE_RC_SUBR=	plexmediaserver_plexpass

SUB_FILES=	plexmediaserver_plexpass
SUB_LIST=	SUPPORT_PATH=${SUPPORT_PATH} SCRIPT_PATH="${SCRIPT_PATH}" USERS=${USERS} GROUPS=${GROUPS}

USERS=	plex
GROUPS=	plex
SUPPORT_PATH?=	${PREFIX}/plexdata${PKGNAMESUFFIX}
SCRIPT_PATH?=	${DATADIR}

ONLY_FOR_ARCHS=	amd64

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
.if ${OSVERSION} < 900000
IGNORE=	supplied binaries compiled for FreeBSD 9
.endif

.if ${OSVERSION} >= 1000054
RUN_DEPENDS+=	${LOCALBASE}/lib/compat/libstdc++.so.6:${PORTSDIR}/misc/compat9x
.endif
.endif

post-patch:
	# binaries don't come pre-stripped
	${FIND} ${WRKSRC} -name '*.so' -exec ${STRIP_CMD} {} \;
	${STRIP_CMD} ${WRKSRC}/Resources/rsync ${WRKSRC}/Resources/Python/bin/python

do-install:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} Resources ${STAGEDIR}/${SCRIPT_PATH})
	${INSTALL_PROGRAM} ${WRKSRC}/Plex\ DLNA\ Server ${STAGEDIR}/${SCRIPT_PATH}
	${INSTALL_PROGRAM} ${WRKSRC}/Plex\ Media\ Scanner ${STAGEDIR}/${SCRIPT_PATH}
	${INSTALL_PROGRAM} ${WRKSRC}/Plex\ Media\ Server ${STAGEDIR}/${SCRIPT_PATH}
	${INSTALL_LIB} ${WRKSRC}/lib* ${STAGEDIR}/${SCRIPT_PATH}
	# Fix permissions to programs and db
	@${CHMOD} a+x ${STAGEDIR}/${SCRIPT_PATH}/Resources/rsync
	@${CHMOD} a+x ${STAGEDIR}/${SCRIPT_PATH}/Resources/Plex\ New\ Transcoder
	@${CHMOD} a+x ${STAGEDIR}/${SCRIPT_PATH}/Resources/Plex\ Transcoder
	@${CHMOD} a+x ${STAGEDIR}/${SCRIPT_PATH}/Resources/Python/bin/python
	@${CHMOD} u+w ${STAGEDIR}/${SCRIPT_PATH}/Resources/com.plexapp.plugins.library.db
	# Python fix
	@${LN} -s ${SCRIPT_PATH}/libpython2.7.so.1 ${STAGEDIR}/${SCRIPT_PATH}/libpython2.7.so

.include <bsd.port.post.mk>
