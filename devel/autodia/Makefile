# Created by: ijliao
# $FreeBSD$

PORTNAME=	autodia
PORTVERSION=	2.14
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TEEJAY
DISTNAME=	Autodia-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automatic Dia XML - from Source Code and Data

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-HTML-Mason>=0:${PORTSDIR}/www/p5-HTML-Mason
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	GRAPHVIZ SPRINGGRAPH VCG DOCS
OPTIONS_DEFAULT=	GRAPHVIZ SPRINGGRAPH VCG
SPRINGGRAPH_DESC=	SpringGraph support
VCG_DESC=		VCG support

USES=		perl5 shebangfix
SHEBANG_FILES=	autodia.pl
USE_PERL5=	configure

PORTDOCS=	CHANGES CREDITS DEVELOP FAQ INSTALL MANIFEST README TODO

GRAPHVIZ_RUN_DEPENDS=	p5-GraphViz>=0:${PORTSDIR}/graphics/p5-GraphViz
SPRINGGRAPH_RUN_DEPENDS=	p5-SpringGraph>=0:${PORTSDIR}/graphics/p5-SpringGraph
VCG_RUN_DEPENDS=	p5-VCG>=0:${PORTSDIR}/graphics/p5-VCG

pre-configure:
	@${FIND} ${WRKSRC} -name "*.orig" -delete

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
