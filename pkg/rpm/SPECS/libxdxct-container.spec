Name: libxdxct-container
License:        BSD-3-Clause AND Apache-2.0 AND GPL-3.0-or-later AND LGPL-3.0-or-later AND MIT AND GPL-2.0-only
Vendor: XDXCT CORPORATION
Packager: XDXCT CORPORATION <tools@xdxct.com>
URL: https://github.com/XDXCT/libxdxct-container
BuildRequires: make
%{!?_tag: %define _version_tag %{_version}}
%{?_tag: %define _version_tag %{_version}~%{_tag}}
Version: %{_version_tag}
Release: %{release}
Summary: XDXCT container runtime library
%description
The xdxct-container library provides an interface to configure GNU/Linux
containers leveraging XDXCT hardware. The implementation relies on several
kernel subsystems and is designed to be agnostic of the container runtime.

%install
DESTDIR=%{buildroot} %{__make} install prefix=%{_prefix} exec_prefix=%{_exec_prefix} bindir=%{_bindir} libdir=%{_libdir} includedir=%{_includedir} docdir=%{_licensedir}

%package -n %{name}%{_major}
Summary: XDXCT container runtime library
%description -n %{name}%{_major}
The xdxct-container library provides an interface to configure GNU/Linux
containers leveraging XDXCT hardware. The implementation relies on several
kernel subsystems and is designed to be agnostic of the container runtime.

%post -n %{name}%{_major} -p /sbin/ldconfig
%postun -n %{name}%{_major} -p /sbin/ldconfig
%files -n %{name}%{_major}
%license %{_licensedir}/*
%{_libdir}/lib*.so.*

%package devel
Requires: %{name}%{_major}%{?_isa} = %{version}-%{release}
Summary: XDXCT container runtime library (development files)
%description devel
The xdxct-container library provides an interface to configure GNU/Linux
containers leveraging XDXCT hardware. The implementation relies on several
kernel subsystems and is designed to be agnostic of the container runtime.

This package contains the files required to compile programs with the library.
%files devel
%license %{_licensedir}/*
%{_includedir}/*.h
%{_libdir}/lib*.so
%{_libdir}/pkgconfig/*.pc

%package static
Requires: %{name}-devel%{?_isa} = %{version}-%{release}
Summary: XDXCT container runtime library (static library)
%description static
The xdxct-container library provides an interface to configure GNU/Linux
containers leveraging XDXCT hardware. The implementation relies on several
kernel subsystems and is designed to be agnostic of the container runtime.

This package requires the XDXCT driver (>= 340.29) to be installed separately.
%files static
%license %{_licensedir}/*
%{_libdir}/lib*.a

%define debug_package %{nil}
%package -n %{name}%{_major}-debuginfo
Requires: %{name}%{_major}%{?_isa} = %{version}-%{release}
Summary: XDXCT container runtime library (debugging symbols)
%description -n %{name}%{_major}-debuginfo
The xdxct-container library provides an interface to configure GNU/Linux
containers leveraging XDXCT hardware. The implementation relies on several
kernel subsystems and is designed to be agnostic of the container runtime.

This package contains the debugging symbols for the library.
%files -n %{name}%{_major}-debuginfo
%license %{_licensedir}/*
%{_prefix}/lib/debug%{_libdir}/lib*.so.*

%package tools
Requires: %{name}%{_major}%{?_isa} >= %{version}-%{release}
Summary: XDXCT container runtime library (command-line tools)
%description tools
The xdxct-container library provides an interface to configure GNU/Linux
containers leveraging XDXCT hardware. The implementation relies on several
kernel subsystems and is designed to be agnostic of the container runtime.

This package contains command-line tools that facilitate using the library.
%files tools
%license %{_licensedir}/*
%{_bindir}/*

%changelog
* Mon Apr 24 2023 XDXCT CORPORATION <tools@xdxct.com> 1.0.0-rc.1-0
- Remove lixdxct-container0 dependency on Ubuntu-based arm64 platforms

* Thu Apr 13 2023 XDXCT CORPORATION <tools@xdxct.com> 1.13.1-1
- Bump version to 1.13.1
