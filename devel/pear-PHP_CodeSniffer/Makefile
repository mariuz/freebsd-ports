# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	PHP_CodeSniffer
PORTVERSION=	1.5.4
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP Script Tokenises and Sniffs PHP and JavaScript code

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
