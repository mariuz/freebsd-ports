# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	OpenCA-OpenSSL
PORTVERSION=	2.0.29
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MADWOLF
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl crypto extension to OpenSSL

BUILD_DEPENDS=	p5-Locale-libintl>=0:${PORTSDIR}/devel/p5-Locale-libintl \
		p5-MIME-Tools>=0:${PORTSDIR}/mail/p5-MIME-Tools \
		p5-X500-DN>=0:${PORTSDIR}/net/p5-X500-DN
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
