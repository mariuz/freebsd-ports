# Created by: Neal Nelson <neal@nelson.name>
# $FreeBSD$

PORTNAME=	twistedPair
PORTVERSION=	14.0.0
CATEGORIES=	net devel python
MASTER_SITES=	http://twistedmatrix.com/Releases/Pair/${PORTVERSION:R}/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedPair-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Twisted Pair can do low level TCP work

LICENSE=	MIT

USE_PYTHON=	2
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes
USES=		tar:bzip2 twisted

.include <bsd.port.mk>
