# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Template-Declare
PORTVERSION=	0.46
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perlish declarative templates

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

COMMON_DEPENDS=	p5-Test-Warn>=0.11:${PORTSDIR}/devel/p5-Test-Warn \
		p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-HTML-Lint>0:${PORTSDIR}/www/p5-HTML-Lint \
		p5-Class-ISA>0:${PORTSDIR}/devel/p5-Class-ISA \
		p5-String-BufferStack>=1.10:${PORTSDIR}/textproc/p5-String-BufferStack
BUILD_DEPENDS=	${COMMON_DEPENDS}
RUN_DEPENDS=	${COMMON_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
