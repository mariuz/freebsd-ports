# Created by: Shin'ya Murakami <murakami@ahs.scitec.kobe-u.ac.jp>
# $FreeBSD$

PORTNAME=	gphys
PORTVERSION=	1.2.2
PORTREVISION=	3
CATEGORIES=	science ruby
MASTER_SITES=	http://ruby.gfd-dennou.org/products/gphys/release/ \
		http://dennou-h.gfd-dennou.org/library/ruby/products/gphys/release/ \
		http://dennou-q.gfd-dennou.org/library/ruby/products/gphys/release/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	murashin@gfd-dennou.org
COMMENT=	Multi-purpose class to handle gridded physical quantities

OPTIONS_DEFINE=	DOCS EXAMPLES

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/narray.so:${PORTSDIR}/math/ruby-narray \
		${RUBY_SITELIBDIR}/narray_miss.rb:${PORTSDIR}/math/ruby-narray_miss \
		${RUBY_SITEARCHLIBDIR}/numru/dcl_raw.so:${PORTSDIR}/science/ruby-dcl \
		${RUBY_SITEARCHLIBDIR}/numru/netcdfraw.so:${PORTSDIR}/science/ruby-netcdf \
		${RUBY_SITEARCHLIBDIR}/numru/fftw3.so:${PORTSDIR}/math/ruby-fftw3 \
		${RUBY_SITELIBDIR}/numru/misc.rb:${PORTSDIR}/math/ruby-numru_misc \
		${RUBY_SITELIBDIR}/numru/units.rb:${PORTSDIR}/math/ruby-numru_units \
		${RUBY_SITEARCHLIBDIR}/rb_gsl.so:${PORTSDIR}/math/ruby-gsl
BUILD_DEPENDS=	${RUBY_SITEARCHLIBDIR}/narray.so:${PORTSDIR}/math/ruby-narray
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
MAKE_ARGS=	INSTALL_PROG="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}"

EXAMPLESDIR=	${RUBY_MODEXAMPLESDIR}
DOCSDIR=	${RUBY_MODDOCDIR}
PORTEXAMPLES=	sample* test*
PORTDOCS=	ChangeLog LICENSE.txt README TODO_ep_flux doc*

DEPRECATED=	Depends on deprecated math/ruby-narray
EXPIRATION_DATE=	2014-09-20

do-install:
	cd ${WRKSRC} && ${MAKE} ${MAKE_ARGS} install
	cd ${WRKSRC} && ${RUBY} install.rb -d ${STAGEDIR}${RUBY_SITELIBDIR} -b ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in ${PORTEXAMPLES}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${i}" ${STAGEDIR}${EXAMPLESDIR})
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${i}" ${STAGEDIR}${DOCSDIR})
.endfor
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
