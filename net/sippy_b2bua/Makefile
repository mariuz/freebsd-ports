# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sippy_b2bua
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	http://www.b2bua.org/chrome/site/
DISTNAME=	sippy-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	SIP Back-to-back user agent (B2BUA) server with Radius support

USE_PYTHON=	yes
USES=		twisted
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	sippy
DOCSDIR=	${PREFIX}/share/doc/${PYDISTUTILS_PKGNAME}

DOCS=		COPYING README

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
