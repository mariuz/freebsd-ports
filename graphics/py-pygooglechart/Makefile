# Created by: Nicola Vitale	<nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pygooglechart
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	http://pygooglechart.slowchop.com/files/download/ \
		LOCAL/nivit/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Complete Python wrapper for the Google Chart API

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

PORTEXAMPLES=	*
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR} && \
		cd ${WRKSRC}/examples && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
