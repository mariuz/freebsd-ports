# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	htsql-pgsql
PORTVERSION=	2.3.3
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tu}-${PORTVERSION}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Database Query Language (PostgreSQL Backend for HTSQL)

LICENSE=	AGPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}htsql>2.3:${PORTSDIR}/databases/py-htsql \
		${PYTHON_PKGNAMEPREFIX}psycopg2>0:${PORTSDIR}/databases/py-psycopg2

USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
