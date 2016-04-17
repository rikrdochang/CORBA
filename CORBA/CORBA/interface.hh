// This file is generated by omniidl (C++ backend)- omniORB_4_2. Do not edit.
#ifndef __interface_hh__
#define __interface_hh__

#ifndef __CORBA_H_EXTERNAL_GUARD__
#include <omniORB4/CORBA.h>
#endif

#ifndef  USE_stub_in_nt_dll
# define USE_stub_in_nt_dll_NOT_DEFINED_interface
#endif
#ifndef  USE_core_stub_in_nt_dll
# define USE_core_stub_in_nt_dll_NOT_DEFINED_interface
#endif
#ifndef  USE_dyn_stub_in_nt_dll
# define USE_dyn_stub_in_nt_dll_NOT_DEFINED_interface
#endif






#ifdef USE_stub_in_nt_dll
# ifndef USE_core_stub_in_nt_dll
#  define USE_core_stub_in_nt_dll
# endif
# ifndef USE_dyn_stub_in_nt_dll
#  define USE_dyn_stub_in_nt_dll
# endif
#endif

#ifdef _core_attr
# error "A local CPP macro _core_attr has already been defined."
#else
# ifdef  USE_core_stub_in_nt_dll
#  define _core_attr _OMNIORB_NTDLL_IMPORT
# else
#  define _core_attr
# endif
#endif

#ifdef _dyn_attr
# error "A local CPP macro _dyn_attr has already been defined."
#else
# ifdef  USE_dyn_stub_in_nt_dll
#  define _dyn_attr _OMNIORB_NTDLL_IMPORT
# else
#  define _dyn_attr
# endif
#endif



_CORBA_MODULE P2P

_CORBA_MODULE_BEG

  class bytes_var;

  class bytes : public _CORBA_Unbounded_Sequence_Octet {
  public:
    typedef bytes_var _var_type;
    inline bytes() {}
    inline bytes(const bytes& _s)
      : _CORBA_Unbounded_Sequence_Octet(_s) {}

    inline bytes(_CORBA_ULong _max)
      : _CORBA_Unbounded_Sequence_Octet(_max) {}
    inline bytes(_CORBA_ULong _max, _CORBA_ULong _len, ::CORBA::Octet* _val, _CORBA_Boolean _rel=0)
      : _CORBA_Unbounded_Sequence_Octet(_max, _len, _val, _rel) {}

  

    inline bytes& operator = (const bytes& _s) {
      _CORBA_Unbounded_Sequence_Octet::operator=(_s);
      return *this;
    }
  };

  class bytes_out;

  class bytes_var {
  public:
    inline bytes_var() : _pd_seq(0) {}
    inline bytes_var(bytes* _s) : _pd_seq(_s) {}
    inline bytes_var(const bytes_var& _s) {
      if (_s._pd_seq)  _pd_seq = new bytes(*_s._pd_seq);
      else             _pd_seq = 0;
    }
    inline ~bytes_var() { if (_pd_seq)  delete _pd_seq; }
      
    inline bytes_var& operator = (bytes* _s) {
      if (_pd_seq)  delete _pd_seq;
      _pd_seq = _s;
      return *this;
    }
    inline bytes_var& operator = (const bytes_var& _s) {
      if (&_s != this) {
        if (_s._pd_seq) {
          if (!_pd_seq)  _pd_seq = new bytes;
          *_pd_seq = *_s._pd_seq;
        }
        else if (_pd_seq) {
          delete _pd_seq;
          _pd_seq = 0;
        }
      }
      return *this;
    }
    inline ::CORBA::Octet& operator [] (_CORBA_ULong _s) {
      return (*_pd_seq)[_s];
    }

  

    inline bytes* operator -> () { return _pd_seq; }
    inline const bytes* operator -> () const { return _pd_seq; }
#if defined(__GNUG__)
    inline operator bytes& () const { return *_pd_seq; }
#else
    inline operator const bytes& () const { return *_pd_seq; }
    inline operator bytes& () { return *_pd_seq; }
#endif
      
    inline const bytes& in() const { return *_pd_seq; }
    inline bytes&       inout()    { return *_pd_seq; }
    inline bytes*&      out() {
      if (_pd_seq) { delete _pd_seq; _pd_seq = 0; }
      return _pd_seq;
    }
    inline bytes* _retn() { bytes* tmp = _pd_seq; _pd_seq = 0; return tmp; }
      
    friend class bytes_out;
    
  private:
    bytes* _pd_seq;
  };

  class bytes_out {
  public:
    inline bytes_out(bytes*& _s) : _data(_s) { _data = 0; }
    inline bytes_out(bytes_var& _s)
      : _data(_s._pd_seq) { _s = (bytes*) 0; }
    inline bytes_out(const bytes_out& _s) : _data(_s._data) {}
    inline bytes_out& operator = (const bytes_out& _s) {
      _data = _s._data;
      return *this;
    }
    inline bytes_out& operator = (bytes* _s) {
      _data = _s;
      return *this;
    }
    inline operator bytes*&()  { return _data; }
    inline bytes*& ptr()       { return _data; }
    inline bytes* operator->() { return _data; }

    inline ::CORBA::Octet& operator [] (_CORBA_ULong _i) {
      return (*_data)[_i];
    }

  

    bytes*& _data;

  private:
    bytes_out();
    bytes_out& operator=(const bytes_var&);
  };

#ifndef __P2P_mcc__
#define __P2P_mcc__
  class cc;
  class _objref_cc;
  class _impl_cc;
  
  typedef _objref_cc* cc_ptr;
  typedef cc_ptr ccRef;

  class cc_Helper {
  public:
    typedef cc_ptr _ptr_type;

    static _ptr_type _nil();
    static _CORBA_Boolean is_nil(_ptr_type);
    static void release(_ptr_type);
    static void duplicate(_ptr_type);
    static void marshalObjRef(_ptr_type, cdrStream&);
    static _ptr_type unmarshalObjRef(cdrStream&);
  };

  typedef _CORBA_ObjRef_Var<_objref_cc, cc_Helper> cc_var;
  typedef _CORBA_ObjRef_OUT_arg<_objref_cc,cc_Helper > cc_out;

#endif

  // interface cc
  class cc {
  public:
    // Declarations for this interface type.
    typedef cc_ptr _ptr_type;
    typedef cc_var _var_type;

    static _ptr_type _duplicate(_ptr_type);
    static _ptr_type _narrow(::CORBA::Object_ptr);
    static _ptr_type _unchecked_narrow(::CORBA::Object_ptr);
    
    static _ptr_type _nil();

    static inline void _marshalObjRef(_ptr_type, cdrStream&);

    static inline _ptr_type _unmarshalObjRef(cdrStream& s) {
      omniObjRef* o = omniObjRef::_unMarshal(_PD_repoId,s);
      if (o)
        return (_ptr_type) o->_ptrToObjRef(_PD_repoId);
      else
        return _nil();
    }

    static inline _ptr_type _fromObjRef(omniObjRef* o) {
      if (o)
        return (_ptr_type) o->_ptrToObjRef(_PD_repoId);
      else
        return _nil();
    }

    static _core_attr const char* _PD_repoId;

    // Other IDL defined within this scope.
    
  };

  class _objref_cc :
    public virtual ::CORBA::Object,
    public virtual omniObjRef
  {
  public:
    // IDL operations
    void talk(const char* correo, const char* mensaje);
    void init(const char* correo);
    void enviarArchivo(const char* correo1, const ::P2P::bytes& archivo);

    // Constructors
    inline _objref_cc()  { _PR_setobj(0); }  // nil
    _objref_cc(omniIOR*, omniIdentity*);

  protected:
    virtual ~_objref_cc();

    
  private:
    virtual void* _ptrToObjRef(const char*);

    _objref_cc(const _objref_cc&);
    _objref_cc& operator = (const _objref_cc&);
    // not implemented

    friend class cc;
  };

  class _pof_cc : public _OMNI_NS(proxyObjectFactory) {
  public:
    inline _pof_cc() : _OMNI_NS(proxyObjectFactory)(cc::_PD_repoId) {}
    virtual ~_pof_cc();

    virtual omniObjRef* newObjRef(omniIOR*,omniIdentity*);
    virtual _CORBA_Boolean is_a(const char*) const;
  };

  class _impl_cc :
    public virtual omniServant
  {
  public:
    virtual ~_impl_cc();

    virtual void talk(const char* correo, const char* mensaje) = 0;
    virtual void init(const char* correo) = 0;
    virtual void enviarArchivo(const char* correo1, const ::P2P::bytes& archivo) = 0;
    
  public:  // Really protected, workaround for xlC
    virtual _CORBA_Boolean _dispatch(omniCallHandle&);

  private:
    virtual void* _ptrToInterface(const char*);
    virtual const char* _mostDerivedRepoId();
    
  };


  struct amigo {
    typedef _CORBA_ConstrType_Variable_Var<amigo> _var_type;

    
    ::CORBA::String_member correo;

    ::CORBA::Boolean estado;

  

    void operator>>= (cdrStream &) const;
    void operator<<= (cdrStream &);
  };

  typedef amigo::_var_type amigo_var;

  typedef _CORBA_ConstrType_Variable_OUT_arg< amigo,amigo_var > amigo_out;

  class amigos_var;

  class amigos : public _CORBA_Unbounded_Sequence< amigo >  {
  public:
    typedef amigos_var _var_type;
    inline amigos() {}
    inline amigos(const amigos& _s)
      : _CORBA_Unbounded_Sequence< amigo > (_s) {}

    inline amigos(_CORBA_ULong _max)
      : _CORBA_Unbounded_Sequence< amigo > (_max) {}
    inline amigos(_CORBA_ULong _max, _CORBA_ULong _len, amigo* _val, _CORBA_Boolean _rel=0)
      : _CORBA_Unbounded_Sequence< amigo > (_max, _len, _val, _rel) {}

  

    inline amigos& operator = (const amigos& _s) {
      _CORBA_Unbounded_Sequence< amigo > ::operator=(_s);
      return *this;
    }
  };

  class amigos_out;

  class amigos_var {
  public:
    inline amigos_var() : _pd_seq(0) {}
    inline amigos_var(amigos* _s) : _pd_seq(_s) {}
    inline amigos_var(const amigos_var& _s) {
      if (_s._pd_seq)  _pd_seq = new amigos(*_s._pd_seq);
      else             _pd_seq = 0;
    }
    inline ~amigos_var() { if (_pd_seq)  delete _pd_seq; }
      
    inline amigos_var& operator = (amigos* _s) {
      if (_pd_seq)  delete _pd_seq;
      _pd_seq = _s;
      return *this;
    }
    inline amigos_var& operator = (const amigos_var& _s) {
      if (&_s != this) {
        if (_s._pd_seq) {
          if (!_pd_seq)  _pd_seq = new amigos;
          *_pd_seq = *_s._pd_seq;
        }
        else if (_pd_seq) {
          delete _pd_seq;
          _pd_seq = 0;
        }
      }
      return *this;
    }
    inline amigo& operator [] (_CORBA_ULong _s) {
      return (*_pd_seq)[_s];
    }

  

    inline amigos* operator -> () { return _pd_seq; }
    inline const amigos* operator -> () const { return _pd_seq; }
#if defined(__GNUG__)
    inline operator amigos& () const { return *_pd_seq; }
#else
    inline operator const amigos& () const { return *_pd_seq; }
    inline operator amigos& () { return *_pd_seq; }
#endif
      
    inline const amigos& in() const { return *_pd_seq; }
    inline amigos&       inout()    { return *_pd_seq; }
    inline amigos*&      out() {
      if (_pd_seq) { delete _pd_seq; _pd_seq = 0; }
      return _pd_seq;
    }
    inline amigos* _retn() { amigos* tmp = _pd_seq; _pd_seq = 0; return tmp; }
      
    friend class amigos_out;
    
  private:
    amigos* _pd_seq;
  };

  class amigos_out {
  public:
    inline amigos_out(amigos*& _s) : _data(_s) { _data = 0; }
    inline amigos_out(amigos_var& _s)
      : _data(_s._pd_seq) { _s = (amigos*) 0; }
    inline amigos_out(const amigos_out& _s) : _data(_s._data) {}
    inline amigos_out& operator = (const amigos_out& _s) {
      _data = _s._data;
      return *this;
    }
    inline amigos_out& operator = (amigos* _s) {
      _data = _s;
      return *this;
    }
    inline operator amigos*&()  { return _data; }
    inline amigos*& ptr()       { return _data; }
    inline amigos* operator->() { return _data; }

    inline amigo& operator [] (_CORBA_ULong _i) {
      return (*_data)[_i];
    }

  

    amigos*& _data;

  private:
    amigos_out();
    amigos_out& operator=(const amigos_var&);
  };

  class buscar_var;

  class buscar : public _CORBA_Unbounded_Sequence_String {
  public:
    typedef buscar_var _var_type;
    inline buscar() {}
    inline buscar(const buscar& _s)
      : _CORBA_Unbounded_Sequence_String(_s) {}

    inline buscar(_CORBA_ULong _max)
      : _CORBA_Unbounded_Sequence_String(_max) {}
    inline buscar(_CORBA_ULong _max, _CORBA_ULong _len, char** _val, _CORBA_Boolean _rel=0)
      : _CORBA_Unbounded_Sequence_String(_max, _len, _val, _rel) {}

  

    inline buscar& operator = (const buscar& _s) {
      _CORBA_Unbounded_Sequence_String::operator=(_s);
      return *this;
    }
  };

  class buscar_out;

  class buscar_var {
  public:
    inline buscar_var() : _pd_seq(0) {}
    inline buscar_var(buscar* _s) : _pd_seq(_s) {}
    inline buscar_var(const buscar_var& _s) {
      if (_s._pd_seq)  _pd_seq = new buscar(*_s._pd_seq);
      else             _pd_seq = 0;
    }
    inline ~buscar_var() { if (_pd_seq)  delete _pd_seq; }
      
    inline buscar_var& operator = (buscar* _s) {
      if (_pd_seq)  delete _pd_seq;
      _pd_seq = _s;
      return *this;
    }
    inline buscar_var& operator = (const buscar_var& _s) {
      if (&_s != this) {
        if (_s._pd_seq) {
          if (!_pd_seq)  _pd_seq = new buscar;
          *_pd_seq = *_s._pd_seq;
        }
        else if (_pd_seq) {
          delete _pd_seq;
          _pd_seq = 0;
        }
      }
      return *this;
    }
    inline _CORBA_String_element operator [] (_CORBA_ULong _s) {
      return (*_pd_seq)[_s];
    }

  

    inline buscar* operator -> () { return _pd_seq; }
    inline const buscar* operator -> () const { return _pd_seq; }
#if defined(__GNUG__)
    inline operator buscar& () const { return *_pd_seq; }
#else
    inline operator const buscar& () const { return *_pd_seq; }
    inline operator buscar& () { return *_pd_seq; }
#endif
      
    inline const buscar& in() const { return *_pd_seq; }
    inline buscar&       inout()    { return *_pd_seq; }
    inline buscar*&      out() {
      if (_pd_seq) { delete _pd_seq; _pd_seq = 0; }
      return _pd_seq;
    }
    inline buscar* _retn() { buscar* tmp = _pd_seq; _pd_seq = 0; return tmp; }
      
    friend class buscar_out;
    
  private:
    buscar* _pd_seq;
  };

  class buscar_out {
  public:
    inline buscar_out(buscar*& _s) : _data(_s) { _data = 0; }
    inline buscar_out(buscar_var& _s)
      : _data(_s._pd_seq) { _s = (buscar*) 0; }
    inline buscar_out(const buscar_out& _s) : _data(_s._data) {}
    inline buscar_out& operator = (const buscar_out& _s) {
      _data = _s._data;
      return *this;
    }
    inline buscar_out& operator = (buscar* _s) {
      _data = _s;
      return *this;
    }
    inline operator buscar*&()  { return _data; }
    inline buscar*& ptr()       { return _data; }
    inline buscar* operator->() { return _data; }

    inline _CORBA_String_element operator [] (_CORBA_ULong _i) {
      return (*_data)[_i];
    }

  

    buscar*& _data;

  private:
    buscar_out();
    buscar_out& operator=(const buscar_var&);
  };

#ifndef __P2P_msc__
#define __P2P_msc__
  class sc;
  class _objref_sc;
  class _impl_sc;
  
  typedef _objref_sc* sc_ptr;
  typedef sc_ptr scRef;

  class sc_Helper {
  public:
    typedef sc_ptr _ptr_type;

    static _ptr_type _nil();
    static _CORBA_Boolean is_nil(_ptr_type);
    static void release(_ptr_type);
    static void duplicate(_ptr_type);
    static void marshalObjRef(_ptr_type, cdrStream&);
    static _ptr_type unmarshalObjRef(cdrStream&);
  };

  typedef _CORBA_ObjRef_Var<_objref_sc, sc_Helper> sc_var;
  typedef _CORBA_ObjRef_OUT_arg<_objref_sc,sc_Helper > sc_out;

#endif

  // interface sc
  class sc {
  public:
    // Declarations for this interface type.
    typedef sc_ptr _ptr_type;
    typedef sc_var _var_type;

    static _ptr_type _duplicate(_ptr_type);
    static _ptr_type _narrow(::CORBA::Object_ptr);
    static _ptr_type _unchecked_narrow(::CORBA::Object_ptr);
    
    static _ptr_type _nil();

    static inline void _marshalObjRef(_ptr_type, cdrStream&);

    static inline _ptr_type _unmarshalObjRef(cdrStream& s) {
      omniObjRef* o = omniObjRef::_unMarshal(_PD_repoId,s);
      if (o)
        return (_ptr_type) o->_ptrToObjRef(_PD_repoId);
      else
        return _nil();
    }

    static inline _ptr_type _fromObjRef(omniObjRef* o) {
      if (o)
        return (_ptr_type) o->_ptrToObjRef(_PD_repoId);
      else
        return _nil();
    }

    static _core_attr const char* _PD_repoId;

    // Other IDL defined within this scope.
    
  };

  class _objref_sc :
    public virtual ::CORBA::Object,
    public virtual omniObjRef
  {
  public:
    // IDL operations
    void sendAmistad(const char* correo);
    void notificar(const char* correo, ::CORBA::Boolean estado);

    // Constructors
    inline _objref_sc()  { _PR_setobj(0); }  // nil
    _objref_sc(omniIOR*, omniIdentity*);

  protected:
    virtual ~_objref_sc();

    
  private:
    virtual void* _ptrToObjRef(const char*);

    _objref_sc(const _objref_sc&);
    _objref_sc& operator = (const _objref_sc&);
    // not implemented

    friend class sc;
  };

  class _pof_sc : public _OMNI_NS(proxyObjectFactory) {
  public:
    inline _pof_sc() : _OMNI_NS(proxyObjectFactory)(sc::_PD_repoId) {}
    virtual ~_pof_sc();

    virtual omniObjRef* newObjRef(omniIOR*,omniIdentity*);
    virtual _CORBA_Boolean is_a(const char*) const;
  };

  class _impl_sc :
    public virtual omniServant
  {
  public:
    virtual ~_impl_sc();

    virtual void sendAmistad(const char* correo) = 0;
    virtual void notificar(const char* correo, ::CORBA::Boolean estado) = 0;
    
  public:  // Really protected, workaround for xlC
    virtual _CORBA_Boolean _dispatch(omniCallHandle&);

  private:
    virtual void* _ptrToInterface(const char*);
    virtual const char* _mostDerivedRepoId();
    
  };


#ifndef __P2P_mcs__
#define __P2P_mcs__
  class cs;
  class _objref_cs;
  class _impl_cs;
  
  typedef _objref_cs* cs_ptr;
  typedef cs_ptr csRef;

  class cs_Helper {
  public:
    typedef cs_ptr _ptr_type;

    static _ptr_type _nil();
    static _CORBA_Boolean is_nil(_ptr_type);
    static void release(_ptr_type);
    static void duplicate(_ptr_type);
    static void marshalObjRef(_ptr_type, cdrStream&);
    static _ptr_type unmarshalObjRef(cdrStream&);
  };

  typedef _CORBA_ObjRef_Var<_objref_cs, cs_Helper> cs_var;
  typedef _CORBA_ObjRef_OUT_arg<_objref_cs,cs_Helper > cs_out;

#endif

  // interface cs
  class cs {
  public:
    // Declarations for this interface type.
    typedef cs_ptr _ptr_type;
    typedef cs_var _var_type;

    static _ptr_type _duplicate(_ptr_type);
    static _ptr_type _narrow(::CORBA::Object_ptr);
    static _ptr_type _unchecked_narrow(::CORBA::Object_ptr);
    
    static _ptr_type _nil();

    static inline void _marshalObjRef(_ptr_type, cdrStream&);

    static inline _ptr_type _unmarshalObjRef(cdrStream& s) {
      omniObjRef* o = omniObjRef::_unMarshal(_PD_repoId,s);
      if (o)
        return (_ptr_type) o->_ptrToObjRef(_PD_repoId);
      else
        return _nil();
    }

    static inline _ptr_type _fromObjRef(omniObjRef* o) {
      if (o)
        return (_ptr_type) o->_ptrToObjRef(_PD_repoId);
      else
        return _nil();
    }

    static _core_attr const char* _PD_repoId;

    // Other IDL defined within this scope.
    
  };

  class _objref_cs :
    public virtual ::CORBA::Object,
    public virtual omniObjRef
  {
  public:
    // IDL operations
    ::CORBA::Boolean pedirAmistad(const char* correo1, const char* correo2);
    amigos* logueo(const char* correo, const char* pass);
    ::CORBA::Boolean registro(const char* correo, const char* pass, const char* nombre);
    ::CORBA::Boolean desregistro(const char* correo);
    ::CORBA::Boolean modPass(const char* correo, const char* pass1, const char* pass2);
    ::CORBA::Boolean deslogueo(const char* correo);
    ::CORBA::Boolean aceptarAmistad(const char* correo1, const char* correo2);
    buscar* buscaAmigos(const char* nombre, const char* correo);
    ::CORBA::Boolean noAmistad(const char* correo1, const char* correo2);
    void initAmistad(const char* correo1);

    // Constructors
    inline _objref_cs()  { _PR_setobj(0); }  // nil
    _objref_cs(omniIOR*, omniIdentity*);

  protected:
    virtual ~_objref_cs();

    
  private:
    virtual void* _ptrToObjRef(const char*);

    _objref_cs(const _objref_cs&);
    _objref_cs& operator = (const _objref_cs&);
    // not implemented

    friend class cs;
  };

  class _pof_cs : public _OMNI_NS(proxyObjectFactory) {
  public:
    inline _pof_cs() : _OMNI_NS(proxyObjectFactory)(cs::_PD_repoId) {}
    virtual ~_pof_cs();

    virtual omniObjRef* newObjRef(omniIOR*,omniIdentity*);
    virtual _CORBA_Boolean is_a(const char*) const;
  };

  class _impl_cs :
    public virtual omniServant
  {
  public:
    virtual ~_impl_cs();

    virtual ::CORBA::Boolean pedirAmistad(const char* correo1, const char* correo2) = 0;
    virtual amigos* logueo(const char* correo, const char* pass) = 0;
    virtual ::CORBA::Boolean registro(const char* correo, const char* pass, const char* nombre) = 0;
    virtual ::CORBA::Boolean desregistro(const char* correo) = 0;
    virtual ::CORBA::Boolean modPass(const char* correo, const char* pass1, const char* pass2) = 0;
    virtual ::CORBA::Boolean deslogueo(const char* correo) = 0;
    virtual ::CORBA::Boolean aceptarAmistad(const char* correo1, const char* correo2) = 0;
    virtual buscar* buscaAmigos(const char* nombre, const char* correo) = 0;
    virtual ::CORBA::Boolean noAmistad(const char* correo1, const char* correo2) = 0;
    virtual void initAmistad(const char* correo1) = 0;
    
  public:  // Really protected, workaround for xlC
    virtual _CORBA_Boolean _dispatch(omniCallHandle&);

  private:
    virtual void* _ptrToInterface(const char*);
    virtual const char* _mostDerivedRepoId();
    
  };


_CORBA_MODULE_END



_CORBA_MODULE POA_P2P
_CORBA_MODULE_BEG

  class cc :
    public virtual P2P::_impl_cc,
    public virtual ::PortableServer::ServantBase
  {
  public:
    virtual ~cc();

    inline ::P2P::cc_ptr _this() {
      return (::P2P::cc_ptr) _do_this(::P2P::cc::_PD_repoId);
    }
  };

  class sc :
    public virtual P2P::_impl_sc,
    public virtual ::PortableServer::ServantBase
  {
  public:
    virtual ~sc();

    inline ::P2P::sc_ptr _this() {
      return (::P2P::sc_ptr) _do_this(::P2P::sc::_PD_repoId);
    }
  };

  class cs :
    public virtual P2P::_impl_cs,
    public virtual ::PortableServer::ServantBase
  {
  public:
    virtual ~cs();

    inline ::P2P::cs_ptr _this() {
      return (::P2P::cs_ptr) _do_this(::P2P::cs::_PD_repoId);
    }
  };

_CORBA_MODULE_END



_CORBA_MODULE OBV_P2P
_CORBA_MODULE_BEG

_CORBA_MODULE_END





#undef _core_attr
#undef _dyn_attr



inline void
P2P::cc::_marshalObjRef(::P2P::cc_ptr obj, cdrStream& s) {
  omniObjRef::_marshal(obj->_PR_getobj(),s);
}

inline void
P2P::sc::_marshalObjRef(::P2P::sc_ptr obj, cdrStream& s) {
  omniObjRef::_marshal(obj->_PR_getobj(),s);
}

inline void
P2P::cs::_marshalObjRef(::P2P::cs_ptr obj, cdrStream& s) {
  omniObjRef::_marshal(obj->_PR_getobj(),s);
}



#ifdef   USE_stub_in_nt_dll_NOT_DEFINED_interface
# undef  USE_stub_in_nt_dll
# undef  USE_stub_in_nt_dll_NOT_DEFINED_interface
#endif
#ifdef   USE_core_stub_in_nt_dll_NOT_DEFINED_interface
# undef  USE_core_stub_in_nt_dll
# undef  USE_core_stub_in_nt_dll_NOT_DEFINED_interface
#endif
#ifdef   USE_dyn_stub_in_nt_dll_NOT_DEFINED_interface
# undef  USE_dyn_stub_in_nt_dll
# undef  USE_dyn_stub_in_nt_dll_NOT_DEFINED_interface
#endif

#endif  // __interface_hh__

