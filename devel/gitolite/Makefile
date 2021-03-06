# $FreeBSD$

PORTNAME=	gitolite
PORTVERSION=	3.6.1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	GH \
		LOCAL/milki \
		LOCAL/tdb
DISTNAME=	g-${GH_ACCOUNT}-${GH_PROJECT}-${PORTVERSION}-${GH_COMMIT}

MAINTAINER=	milki@FreeBSD.org
COMMENT=	Access control layer on top of git

LICENSE=	GPLv2

RUN_DEPENDS=	git>=0:${PORTSDIR}/devel/git \
	p5-JSON>=0:${PORTSDIR}/converters/p5-JSON

USE_GITHUB=	yes
GH_ACCOUNT=	sitaramc
GH_COMMIT=	3455375
GH_TAGNAME=	${GH_COMMIT}

CONFLICTS=	gitolite-[^3]*

USES=		perl5

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	GITUSER DOCS

GITUSER_DESC=	Create git user as gitolite provider

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGITUSER}
USERS=		git
GROUPS=		${USERS}
PLIST_SUB+=	GITUSER=""
.else
PLIST_SUB+=	GITUSER="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC} \
		-exec ${GREP} -qs \#\!/usr/bin/perl {} \; \
		-exec ${REINPLACE_CMD} -Ee 's|#!/usr/bin/perl|#!${PERL}|' {} \;
	@${FIND} ${WRKSRC} \
		-exec ${GREP} -qs \#\!/bin/bash {} \; \
		-exec ${REINPLACE_CMD} -Ee 's|#!/bin/bash|#!${LOCALBASE}/bin/bash|' {} \;

do-build:
	echo "v${PORTVERSION}-0-g${GH_COMMIT}" > ${WRKSRC}/src/VERSION
	${MKDIR} ${WRKSRC}/lib
	${MV} ${WRKSRC}/src/lib/Gitolite ${WRKSRC}/lib/
	${RMDIR} ${WRKSRC}/src/lib
	${MV} ${WRKSRC}/check-g2-compat ${WRKSRC}/src/
	${MV} ${WRKSRC}/convert-gitosis-conf ${WRKSRC}/src/

post-build:
	${FIND} ${WRKSRC} -name "*.bak" -delete
	${FIND} ${WRKSRC} -name "*.orig" -delete

do-install:
	(cd ${WRKSRC}/src && ${COPYTREE_BIN} \* ${STAGEDIR}${PREFIX}/libexec/gitolite)
	(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} Gitolite ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/)
	${LN} -s ${PREFIX}/libexec/gitolite/gitolite ${STAGEDIR}${PREFIX}/bin/gitolite

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/CHANGELOG ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
