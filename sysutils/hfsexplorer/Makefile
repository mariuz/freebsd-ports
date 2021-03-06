# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	hfsexplorer
PORTVERSION=	0.21
PORTREVISION=	1
CATEGORIES=	sysutils java
MASTER_SITES=	SF/catacombae/HFSExplorer/${PORTVERSION}/
DISTNAME=	${PORTNAME}-0_21-src

MAINTAINER=	vg@FreeBSD.org
COMMENT=	HFSExplorer read Mac-formatted harddisks and disk images

BUILD_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant

LICENSE=	GPLv3

DESKTOP_ENTRIES="hfsexplorer" "reader Mac-formatted harddisk" \
		"${DATADIR}/res/icon.png" "${PORTNAME}" \
		"System;Utility;Java;" false

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6
OPTIONS_DEFINE= DOCS
WRKSRC=		${WRKDIR}

.include <bsd.port.options.mk>

do-configure:
	@cd ${WRKSRC}/dist && ${REINPLACE_CMD} -e 's|lib/|${DATADIR}/lib/|g' \
		hfsx.sh resview.sh unhfs.sh
	@${REINPLACE_CMD} -e 's|lib|${DATADIR}/lib|g' \
		${WRKSRC}/dist/runfsb.sh

do-build:
	@cd ${WRKSRC} && ${SH} buildall.sh

do-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/dist/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}/
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib
	@${MKDIR} ${STAGEDIR}${DATADIR}/res
.for f in hfsx.sh resview.sh unhfs.sh
	@cd ${WRKSRC} && ${INSTALL_SCRIPT} dist/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	@cd ${WRKSRC} && ${INSTALL_SCRIPT} dist/runfsb.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@cd ${WRKSRC} && ${INSTALL_DATA} dist/lib/*.jar ${STAGEDIR}${DATADIR}/lib
	@cd ${WRKSRC} && ${INSTALL_DATA} dist/res/icon.png ${STAGEDIR}${DATADIR}/res

.include <bsd.port.mk>
