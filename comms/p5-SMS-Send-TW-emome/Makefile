# Created by: Tsung-Han Yeh <snowfly@yuntech.edu.tw>
# $FreeBSD$

PORTNAME=	SMS-Send-TW-emome
PORTVERSION=	0.04
CATEGORIES=	comms perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	SMS::Send driver for www.emome.net

RUN_DEPENDS=	p5-SMS-Send>=0.03:${PORTSDIR}/comms/p5-SMS-Send \
  		p5-Crypt-SSLeay>=0.57:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-WWW-Mechanize>=1.20:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-Text-Iconv>=:${PORTSDIR}/converters/p5-Text-Iconv
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
