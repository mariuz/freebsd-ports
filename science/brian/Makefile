# Created by: wenheping@gmail.com
# $FreeBSD$

PORTNAME=	brian
PORTVERSION=	1.4.1
PORTREVISION=	4
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Clock-driven simulator for spiking neural networks

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.1.0:${PORTSDIR}/math/py-numpy \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.6.0:${PORTSDIR}/science/py-scipy \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0.90.1:${PORTSDIR}/math/py-matplotlib
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		zip
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
