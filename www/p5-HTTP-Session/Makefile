# $FreeBSD$

PORTNAME=	HTTP-Session
PORTVERSION=	0.48
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOKUHIROM
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of yet another session manager

RUN_DEPENDS=	\
	p5-Class-Accessor>=0.31:${PORTSDIR}/devel/p5-Class-Accessor \
	p5-CGI-Simple>=1.103:${PORTSDIR}/www/p5-CGI-Simple \
	p5-CHI>0:${PORTSDIR}/devel/p5-CHI \
	p5-Digest-SHA1>=2.11:${PORTSDIR}/security/p5-Digest-SHA1 \
	p5-HTML-StickyQuery>0:${PORTSDIR}/www/p5-HTML-StickyQuery \
	p5-libwww>=5.818:${PORTSDIR}/www/p5-libwww \
	p5-Module-Runtime>=0.011:${PORTSDIR}/devel/p5-Module-Runtime \
	p5-URI>=1.38:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Requires>0:${PORTSDIR}/devel/p5-Test-Requires \
	p5-Test-Memory-Cycle>0:${PORTSDIR}/devel/p5-Test-Memory-Cycle

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
