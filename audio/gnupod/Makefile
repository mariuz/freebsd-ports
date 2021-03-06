# Created by: David Le Brun <david@dyn-ns.net>
# $FreeBSD$

PORTNAME=	gnupod
PORTVERSION=	0.99.8
PORTREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_SAVANNAH} \
		http://www.blinkenlights.ch/gnupod-dist/stable/
MASTER_SITE_SUBDIR=	gnupod

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of Perl scripts for using an Apple iPod

BUILD_DEPENDS=	p5-MP3-Info>=0:${PORTSDIR}/audio/p5-MP3-Info \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate \
		p5-Unicode-String>=0:${PORTSDIR}/converters/p5-Unicode-String \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1
RUN_DEPENDS:=	${BUILD_DEPENDS}

INFO=		gnupod

USES=		makeinfo perl5 tar:tgz
GNU_CONFIGURE=	yes
NO_BUILD=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX}
CONFIGURE_ENV=	ac_cv_path_PERL=${PERL}

OPTIONS_DEFINE=	FLAC VORBIS DOCS

FLAC_BUILD_DEPENDS=	p5-Audio-FLAC-Header>=0:${PORTSDIR}/audio/p5-Audio-FLAC-Header
VORBIS_BUILD_DEPENDS=	p5-Ogg-Vorbis-Header-PurePerl>=0:${PORTSDIR}/audio/p5-Ogg-Vorbis-Header-PurePerl \
			oggdec:${PORTSDIR}/audio/vorbis-tools

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${STAGEDIR}${DOCSDIR}
.for file in gnupodrc.example gnutunesdb.example gnupod.html mkspl.html \
gnupod.texi fdl.texi version.texi ipod.svg
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
