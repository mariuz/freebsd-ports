# $FreeBSD$

PORTNAME=	diazo
PORTVERSION=	1.0.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Implements a Deliverance like language using a pure XSLT engine

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}experimental.cssselect>0:${PORTSDIR}/devel/py-experimental.cssselect \
		${PYTHON_PKGNAMEPREFIX}repoze.xmliter>=0.3:${PORTSDIR}/devel/py-repoze.xmliter \
		${PYTHON_PKGNAMEPREFIX}webob>=0:${PORTSDIR}/www/py-webob

USES=			zip
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
