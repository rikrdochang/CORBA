// This file is generated by omniidl (C++ backend)- omniORB_4_2. Do not edit.

#include "interface.hh"
#include <omniORB4/IOP_S.h>
#include <omniORB4/IOP_C.h>
#include <omniORB4/callDescriptor.h>
#include <omniORB4/callHandle.h>
#include <omniORB4/objTracker.h>


OMNI_USING_NAMESPACE(omni)

static const char* _0RL_library_version = omniORB_4_2;



P2P::cc_ptr P2P::cc_Helper::_nil() {
  return ::P2P::cc::_nil();
}

::CORBA::Boolean P2P::cc_Helper::is_nil(::P2P::cc_ptr p) {
  return ::CORBA::is_nil(p);

}

void P2P::cc_Helper::release(::P2P::cc_ptr p) {
  ::CORBA::release(p);
}

void P2P::cc_Helper::marshalObjRef(::P2P::cc_ptr obj, cdrStream& s) {
  ::P2P::cc::_marshalObjRef(obj, s);
}

P2P::cc_ptr P2P::cc_Helper::unmarshalObjRef(cdrStream& s) {
  return ::P2P::cc::_unmarshalObjRef(s);
}

void P2P::cc_Helper::duplicate(::P2P::cc_ptr obj) {
  if (obj && !obj->_NP_is_nil())  omni::duplicateObjRef(obj);
}

P2P::cc_ptr
P2P::cc::_duplicate(::P2P::cc_ptr obj)
{
  if (obj && !obj->_NP_is_nil())  omni::duplicateObjRef(obj);
  return obj;
}

P2P::cc_ptr
P2P::cc::_narrow(::CORBA::Object_ptr obj)
{
  if (!obj || obj->_NP_is_nil() || obj->_NP_is_pseudo()) return _nil();
  _ptr_type e = (_ptr_type) obj->_PR_getobj()->_realNarrow(_PD_repoId);
  return e ? e : _nil();
}


P2P::cc_ptr
P2P::cc::_unchecked_narrow(::CORBA::Object_ptr obj)
{
  if (!obj || obj->_NP_is_nil() || obj->_NP_is_pseudo()) return _nil();
  _ptr_type e = (_ptr_type) obj->_PR_getobj()->_uncheckedNarrow(_PD_repoId);
  return e ? e : _nil();
}

P2P::cc_ptr
P2P::cc::_nil()
{
#ifdef OMNI_UNLOADABLE_STUBS
  static _objref_cc _the_nil_obj;
  return &_the_nil_obj;
#else
  static _objref_cc* _the_nil_ptr = 0;
  if (!_the_nil_ptr) {
    omni::nilRefLock().lock();
    if (!_the_nil_ptr) {
      _the_nil_ptr = new _objref_cc;
      registerNilCorbaObject(_the_nil_ptr);
    }
    omni::nilRefLock().unlock();
  }
  return _the_nil_ptr;
#endif
}

const char* P2P::cc::_PD_repoId = "IDL:P2P/cc:1.0";


P2P::_objref_cc::~_objref_cc() {
  
}


P2P::_objref_cc::_objref_cc(omniIOR* ior, omniIdentity* id) :
   omniObjRef(::P2P::cc::_PD_repoId, ior, id, 1)
   
   
{
  _PR_setobj(this);
}

void*
P2P::_objref_cc::_ptrToObjRef(const char* id)
{
  if (id == ::P2P::cc::_PD_repoId)
    return (::P2P::cc_ptr) this;
  
  if (id == ::CORBA::Object::_PD_repoId)
    return (::CORBA::Object_ptr) this;

  if (omni::strMatch(id, ::P2P::cc::_PD_repoId))
    return (::P2P::cc_ptr) this;
  
  if (omni::strMatch(id, ::CORBA::Object::_PD_repoId))
    return (::CORBA::Object_ptr) this;

  return 0;
}


//
// Code for P2P::cc::talk

// Proxy call descriptor class. Mangled signature:
//  void_i_cstring_i_cstring
class _0RL_cd_efe87cde4422e9bd_00000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_efe87cde4422e9bd_00000000(LocalCallFn lcfn, const char* op_, size_t oplen, _CORBA_Boolean upcall=0)
    : omniCallDescriptor(lcfn, op_, oplen, 0, _user_exns, 0, upcall)
  {
    
  }
  
  void marshalArguments(cdrStream&);
  void unmarshalArguments(cdrStream&);

    
  
  static const char* const _user_exns[];

  ::CORBA::String_var arg_0_;
  const char* arg_0;
  ::CORBA::String_var arg_1_;
  const char* arg_1;
};

void _0RL_cd_efe87cde4422e9bd_00000000::marshalArguments(cdrStream& _n)
{
  _n.marshalString(arg_0,0);
  _n.marshalString(arg_1,0);

}

void _0RL_cd_efe87cde4422e9bd_00000000::unmarshalArguments(cdrStream& _n)
{
  arg_0_ = _n.unmarshalString(0);
  arg_0 = arg_0_.in();
  arg_1_ = _n.unmarshalString(0);
  arg_1 = arg_1_.in();

}

const char* const _0RL_cd_efe87cde4422e9bd_00000000::_user_exns[] = {
  0
};

// Local call call-back function.
static void
_0RL_lcfn_efe87cde4422e9bd_10000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_efe87cde4422e9bd_00000000* tcd = (_0RL_cd_efe87cde4422e9bd_00000000*)cd;
  P2P::_impl_cc* impl = (P2P::_impl_cc*) svnt->_ptrToInterface(P2P::cc::_PD_repoId);
  impl->talk(tcd->arg_0, tcd->arg_1);


}

void P2P::_objref_cc::talk(const char* correo, const char* mensaje)
{
  _0RL_cd_efe87cde4422e9bd_00000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_10000000, "talk", 5);
  _call_desc.arg_0 = correo;
  _call_desc.arg_1 = mensaje;

  _invoke(_call_desc);



}


//
// Code for P2P::cc::init

// Proxy call descriptor class. Mangled signature:
//  void_i_cstring
class _0RL_cd_efe87cde4422e9bd_20000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_efe87cde4422e9bd_20000000(LocalCallFn lcfn, const char* op_, size_t oplen, _CORBA_Boolean upcall=0)
    : omniCallDescriptor(lcfn, op_, oplen, 0, _user_exns, 0, upcall)
  {
    
  }
  
  void marshalArguments(cdrStream&);
  void unmarshalArguments(cdrStream&);

    
  
  static const char* const _user_exns[];

  ::CORBA::String_var arg_0_;
  const char* arg_0;
};

void _0RL_cd_efe87cde4422e9bd_20000000::marshalArguments(cdrStream& _n)
{
  _n.marshalString(arg_0,0);

}

void _0RL_cd_efe87cde4422e9bd_20000000::unmarshalArguments(cdrStream& _n)
{
  arg_0_ = _n.unmarshalString(0);
  arg_0 = arg_0_.in();

}

const char* const _0RL_cd_efe87cde4422e9bd_20000000::_user_exns[] = {
  0
};

// Local call call-back function.
static void
_0RL_lcfn_efe87cde4422e9bd_30000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_efe87cde4422e9bd_20000000* tcd = (_0RL_cd_efe87cde4422e9bd_20000000*)cd;
  P2P::_impl_cc* impl = (P2P::_impl_cc*) svnt->_ptrToInterface(P2P::cc::_PD_repoId);
  impl->init(tcd->arg_0);


}

void P2P::_objref_cc::init(const char* correo)
{
  _0RL_cd_efe87cde4422e9bd_20000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_30000000, "init", 5);
  _call_desc.arg_0 = correo;

  _invoke(_call_desc);



}


//
// Code for P2P::cc::enviarArchivo

// Proxy call descriptor class. Mangled signature:
//  void_i_cstring_i_cstring_i_cP2P_mbytes
class _0RL_cd_efe87cde4422e9bd_40000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_efe87cde4422e9bd_40000000(LocalCallFn lcfn, const char* op_, size_t oplen, _CORBA_Boolean upcall=0)
    : omniCallDescriptor(lcfn, op_, oplen, 0, _user_exns, 0, upcall)
  {
    
  }
  
  void marshalArguments(cdrStream&);
  void unmarshalArguments(cdrStream&);

    
  
  static const char* const _user_exns[];

  ::CORBA::String_var arg_0_;
  const char* arg_0;
  ::CORBA::String_var arg_1_;
  const char* arg_1;
  P2P::bytes_var arg_2_;
  const P2P::bytes* arg_2;
};

void _0RL_cd_efe87cde4422e9bd_40000000::marshalArguments(cdrStream& _n)
{
  _n.marshalString(arg_0,0);
  _n.marshalString(arg_1,0);
  (const P2P::bytes&) *arg_2 >>= _n;

}

void _0RL_cd_efe87cde4422e9bd_40000000::unmarshalArguments(cdrStream& _n)
{
  arg_0_ = _n.unmarshalString(0);
  arg_0 = arg_0_.in();
  arg_1_ = _n.unmarshalString(0);
  arg_1 = arg_1_.in();
  arg_2_ = new P2P::bytes;
  (P2P::bytes&)arg_2_ <<= _n;
  arg_2 = &arg_2_.in();

}

const char* const _0RL_cd_efe87cde4422e9bd_40000000::_user_exns[] = {
  0
};

// Local call call-back function.
static void
_0RL_lcfn_efe87cde4422e9bd_50000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_efe87cde4422e9bd_40000000* tcd = (_0RL_cd_efe87cde4422e9bd_40000000*)cd;
  P2P::_impl_cc* impl = (P2P::_impl_cc*) svnt->_ptrToInterface(P2P::cc::_PD_repoId);
  impl->enviarArchivo(tcd->arg_0, tcd->arg_1, *tcd->arg_2);


}

void P2P::_objref_cc::enviarArchivo(const char* correo1, const char* nombreArchivo, const ::P2P::bytes& archivo)
{
  _0RL_cd_efe87cde4422e9bd_40000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_50000000, "enviarArchivo", 14);
  _call_desc.arg_0 = correo1;
  _call_desc.arg_1 = nombreArchivo;
  _call_desc.arg_2 = &(::P2P::bytes&) archivo;

  _invoke(_call_desc);



}

P2P::_pof_cc::~_pof_cc() {}


omniObjRef*
P2P::_pof_cc::newObjRef(omniIOR* ior, omniIdentity* id)
{
  return new ::P2P::_objref_cc(ior, id);
}


::CORBA::Boolean
P2P::_pof_cc::is_a(const char* id) const
{
  if (omni::ptrStrMatch(id, ::P2P::cc::_PD_repoId))
    return 1;
  
  return 0;
}

const P2P::_pof_cc _the_pof_P2P_mcc;

P2P::_impl_cc::~_impl_cc() {}


::CORBA::Boolean
P2P::_impl_cc::_dispatch(omniCallHandle& _handle)
{
  const char* op = _handle.operation_name();

  if (omni::strMatch(op, "talk")) {

    _0RL_cd_efe87cde4422e9bd_00000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_10000000, "talk", 5, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if (omni::strMatch(op, "init")) {

    _0RL_cd_efe87cde4422e9bd_20000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_30000000, "init", 5, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if (omni::strMatch(op, "enviarArchivo")) {

    _0RL_cd_efe87cde4422e9bd_40000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_50000000, "enviarArchivo", 14, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }


  return 0;
}

void*
P2P::_impl_cc::_ptrToInterface(const char* id)
{
  if (id == ::P2P::cc::_PD_repoId)
    return (::P2P::_impl_cc*) this;
  
  if (id == ::CORBA::Object::_PD_repoId)
    return (void*) 1;

  if (omni::strMatch(id, ::P2P::cc::_PD_repoId))
    return (::P2P::_impl_cc*) this;
  
  if (omni::strMatch(id, ::CORBA::Object::_PD_repoId))
    return (void*) 1;
  return 0;
}

const char*
P2P::_impl_cc::_mostDerivedRepoId()
{
  return ::P2P::cc::_PD_repoId;
}

void
P2P::amigo::operator>>= (cdrStream &_n) const
{
  _n.marshalString(correo,0);
  _n.marshalBoolean(estado);

}

void
P2P::amigo::operator<<= (cdrStream &_n)
{
  correo = _n.unmarshalString(0);
  estado = _n.unmarshalBoolean();

}

P2P::sc_ptr P2P::sc_Helper::_nil() {
  return ::P2P::sc::_nil();
}

::CORBA::Boolean P2P::sc_Helper::is_nil(::P2P::sc_ptr p) {
  return ::CORBA::is_nil(p);

}

void P2P::sc_Helper::release(::P2P::sc_ptr p) {
  ::CORBA::release(p);
}

void P2P::sc_Helper::marshalObjRef(::P2P::sc_ptr obj, cdrStream& s) {
  ::P2P::sc::_marshalObjRef(obj, s);
}

P2P::sc_ptr P2P::sc_Helper::unmarshalObjRef(cdrStream& s) {
  return ::P2P::sc::_unmarshalObjRef(s);
}

void P2P::sc_Helper::duplicate(::P2P::sc_ptr obj) {
  if (obj && !obj->_NP_is_nil())  omni::duplicateObjRef(obj);
}

P2P::sc_ptr
P2P::sc::_duplicate(::P2P::sc_ptr obj)
{
  if (obj && !obj->_NP_is_nil())  omni::duplicateObjRef(obj);
  return obj;
}

P2P::sc_ptr
P2P::sc::_narrow(::CORBA::Object_ptr obj)
{
  if (!obj || obj->_NP_is_nil() || obj->_NP_is_pseudo()) return _nil();
  _ptr_type e = (_ptr_type) obj->_PR_getobj()->_realNarrow(_PD_repoId);
  return e ? e : _nil();
}


P2P::sc_ptr
P2P::sc::_unchecked_narrow(::CORBA::Object_ptr obj)
{
  if (!obj || obj->_NP_is_nil() || obj->_NP_is_pseudo()) return _nil();
  _ptr_type e = (_ptr_type) obj->_PR_getobj()->_uncheckedNarrow(_PD_repoId);
  return e ? e : _nil();
}

P2P::sc_ptr
P2P::sc::_nil()
{
#ifdef OMNI_UNLOADABLE_STUBS
  static _objref_sc _the_nil_obj;
  return &_the_nil_obj;
#else
  static _objref_sc* _the_nil_ptr = 0;
  if (!_the_nil_ptr) {
    omni::nilRefLock().lock();
    if (!_the_nil_ptr) {
      _the_nil_ptr = new _objref_sc;
      registerNilCorbaObject(_the_nil_ptr);
    }
    omni::nilRefLock().unlock();
  }
  return _the_nil_ptr;
#endif
}

const char* P2P::sc::_PD_repoId = "IDL:P2P/sc:1.0";


P2P::_objref_sc::~_objref_sc() {
  
}


P2P::_objref_sc::_objref_sc(omniIOR* ior, omniIdentity* id) :
   omniObjRef(::P2P::sc::_PD_repoId, ior, id, 1)
   
   
{
  _PR_setobj(this);
}

void*
P2P::_objref_sc::_ptrToObjRef(const char* id)
{
  if (id == ::P2P::sc::_PD_repoId)
    return (::P2P::sc_ptr) this;
  
  if (id == ::CORBA::Object::_PD_repoId)
    return (::CORBA::Object_ptr) this;

  if (omni::strMatch(id, ::P2P::sc::_PD_repoId))
    return (::P2P::sc_ptr) this;
  
  if (omni::strMatch(id, ::CORBA::Object::_PD_repoId))
    return (::CORBA::Object_ptr) this;

  return 0;
}


//
// Code for P2P::sc::sendAmistad

// Local call call-back function.
static void
_0RL_lcfn_efe87cde4422e9bd_60000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_efe87cde4422e9bd_20000000* tcd = (_0RL_cd_efe87cde4422e9bd_20000000*)cd;
  P2P::_impl_sc* impl = (P2P::_impl_sc*) svnt->_ptrToInterface(P2P::sc::_PD_repoId);
  impl->sendAmistad(tcd->arg_0);


}

void P2P::_objref_sc::sendAmistad(const char* correo)
{
  _0RL_cd_efe87cde4422e9bd_20000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_60000000, "sendAmistad", 12);
  _call_desc.arg_0 = correo;

  _invoke(_call_desc);



}


//
// Code for P2P::sc::notificar

// Proxy call descriptor class. Mangled signature:
//  void_i_cstring_i_cboolean
class _0RL_cd_efe87cde4422e9bd_70000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_efe87cde4422e9bd_70000000(LocalCallFn lcfn, const char* op_, size_t oplen, _CORBA_Boolean upcall=0)
    : omniCallDescriptor(lcfn, op_, oplen, 0, _user_exns, 0, upcall)
  {
    
  }
  
  void marshalArguments(cdrStream&);
  void unmarshalArguments(cdrStream&);

    
  
  static const char* const _user_exns[];

  ::CORBA::String_var arg_0_;
  const char* arg_0;
  ::CORBA::Boolean arg_1;
};

void _0RL_cd_efe87cde4422e9bd_70000000::marshalArguments(cdrStream& _n)
{
  _n.marshalString(arg_0,0);
  _n.marshalBoolean(arg_1);

}

void _0RL_cd_efe87cde4422e9bd_70000000::unmarshalArguments(cdrStream& _n)
{
  arg_0_ = _n.unmarshalString(0);
  arg_0 = arg_0_.in();
  arg_1 = _n.unmarshalBoolean();

}

const char* const _0RL_cd_efe87cde4422e9bd_70000000::_user_exns[] = {
  0
};

// Local call call-back function.
static void
_0RL_lcfn_efe87cde4422e9bd_80000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_efe87cde4422e9bd_70000000* tcd = (_0RL_cd_efe87cde4422e9bd_70000000*)cd;
  P2P::_impl_sc* impl = (P2P::_impl_sc*) svnt->_ptrToInterface(P2P::sc::_PD_repoId);
  impl->notificar(tcd->arg_0, tcd->arg_1);


}

void P2P::_objref_sc::notificar(const char* correo, ::CORBA::Boolean estado)
{
  _0RL_cd_efe87cde4422e9bd_70000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_80000000, "notificar", 10);
  _call_desc.arg_0 = correo;
  _call_desc.arg_1 = estado;

  _invoke(_call_desc);



}

P2P::_pof_sc::~_pof_sc() {}


omniObjRef*
P2P::_pof_sc::newObjRef(omniIOR* ior, omniIdentity* id)
{
  return new ::P2P::_objref_sc(ior, id);
}


::CORBA::Boolean
P2P::_pof_sc::is_a(const char* id) const
{
  if (omni::ptrStrMatch(id, ::P2P::sc::_PD_repoId))
    return 1;
  
  return 0;
}

const P2P::_pof_sc _the_pof_P2P_msc;

P2P::_impl_sc::~_impl_sc() {}


::CORBA::Boolean
P2P::_impl_sc::_dispatch(omniCallHandle& _handle)
{
  const char* op = _handle.operation_name();

  if (omni::strMatch(op, "sendAmistad")) {

    _0RL_cd_efe87cde4422e9bd_20000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_60000000, "sendAmistad", 12, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if (omni::strMatch(op, "notificar")) {

    _0RL_cd_efe87cde4422e9bd_70000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_80000000, "notificar", 10, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }


  return 0;
}

void*
P2P::_impl_sc::_ptrToInterface(const char* id)
{
  if (id == ::P2P::sc::_PD_repoId)
    return (::P2P::_impl_sc*) this;
  
  if (id == ::CORBA::Object::_PD_repoId)
    return (void*) 1;

  if (omni::strMatch(id, ::P2P::sc::_PD_repoId))
    return (::P2P::_impl_sc*) this;
  
  if (omni::strMatch(id, ::CORBA::Object::_PD_repoId))
    return (void*) 1;
  return 0;
}

const char*
P2P::_impl_sc::_mostDerivedRepoId()
{
  return ::P2P::sc::_PD_repoId;
}

P2P::cs_ptr P2P::cs_Helper::_nil() {
  return ::P2P::cs::_nil();
}

::CORBA::Boolean P2P::cs_Helper::is_nil(::P2P::cs_ptr p) {
  return ::CORBA::is_nil(p);

}

void P2P::cs_Helper::release(::P2P::cs_ptr p) {
  ::CORBA::release(p);
}

void P2P::cs_Helper::marshalObjRef(::P2P::cs_ptr obj, cdrStream& s) {
  ::P2P::cs::_marshalObjRef(obj, s);
}

P2P::cs_ptr P2P::cs_Helper::unmarshalObjRef(cdrStream& s) {
  return ::P2P::cs::_unmarshalObjRef(s);
}

void P2P::cs_Helper::duplicate(::P2P::cs_ptr obj) {
  if (obj && !obj->_NP_is_nil())  omni::duplicateObjRef(obj);
}

P2P::cs_ptr
P2P::cs::_duplicate(::P2P::cs_ptr obj)
{
  if (obj && !obj->_NP_is_nil())  omni::duplicateObjRef(obj);
  return obj;
}

P2P::cs_ptr
P2P::cs::_narrow(::CORBA::Object_ptr obj)
{
  if (!obj || obj->_NP_is_nil() || obj->_NP_is_pseudo()) return _nil();
  _ptr_type e = (_ptr_type) obj->_PR_getobj()->_realNarrow(_PD_repoId);
  return e ? e : _nil();
}


P2P::cs_ptr
P2P::cs::_unchecked_narrow(::CORBA::Object_ptr obj)
{
  if (!obj || obj->_NP_is_nil() || obj->_NP_is_pseudo()) return _nil();
  _ptr_type e = (_ptr_type) obj->_PR_getobj()->_uncheckedNarrow(_PD_repoId);
  return e ? e : _nil();
}

P2P::cs_ptr
P2P::cs::_nil()
{
#ifdef OMNI_UNLOADABLE_STUBS
  static _objref_cs _the_nil_obj;
  return &_the_nil_obj;
#else
  static _objref_cs* _the_nil_ptr = 0;
  if (!_the_nil_ptr) {
    omni::nilRefLock().lock();
    if (!_the_nil_ptr) {
      _the_nil_ptr = new _objref_cs;
      registerNilCorbaObject(_the_nil_ptr);
    }
    omni::nilRefLock().unlock();
  }
  return _the_nil_ptr;
#endif
}

const char* P2P::cs::_PD_repoId = "IDL:P2P/cs:1.0";


P2P::_objref_cs::~_objref_cs() {
  
}


P2P::_objref_cs::_objref_cs(omniIOR* ior, omniIdentity* id) :
   omniObjRef(::P2P::cs::_PD_repoId, ior, id, 1)
   
   
{
  _PR_setobj(this);
}

void*
P2P::_objref_cs::_ptrToObjRef(const char* id)
{
  if (id == ::P2P::cs::_PD_repoId)
    return (::P2P::cs_ptr) this;
  
  if (id == ::CORBA::Object::_PD_repoId)
    return (::CORBA::Object_ptr) this;

  if (omni::strMatch(id, ::P2P::cs::_PD_repoId))
    return (::P2P::cs_ptr) this;
  
  if (omni::strMatch(id, ::CORBA::Object::_PD_repoId))
    return (::CORBA::Object_ptr) this;

  return 0;
}


//
// Code for P2P::cs::pedirAmistad

// Proxy call descriptor class. Mangled signature:
//  _cshort_i_cstring_i_cstring
class _0RL_cd_efe87cde4422e9bd_90000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_efe87cde4422e9bd_90000000(LocalCallFn lcfn, const char* op_, size_t oplen, _CORBA_Boolean upcall=0)
    : omniCallDescriptor(lcfn, op_, oplen, 0, _user_exns, 0, upcall)
  {
    
  }
  
  void marshalArguments(cdrStream&);
  void unmarshalArguments(cdrStream&);

  void unmarshalReturnedValues(cdrStream&);
  void marshalReturnedValues(cdrStream&);
  
  
  static const char* const _user_exns[];

  ::CORBA::String_var arg_0_;
  const char* arg_0;
  ::CORBA::String_var arg_1_;
  const char* arg_1;
  ::CORBA::Short result;
};

void _0RL_cd_efe87cde4422e9bd_90000000::marshalArguments(cdrStream& _n)
{
  _n.marshalString(arg_0,0);
  _n.marshalString(arg_1,0);

}

void _0RL_cd_efe87cde4422e9bd_90000000::unmarshalArguments(cdrStream& _n)
{
  arg_0_ = _n.unmarshalString(0);
  arg_0 = arg_0_.in();
  arg_1_ = _n.unmarshalString(0);
  arg_1 = arg_1_.in();

}

void _0RL_cd_efe87cde4422e9bd_90000000::marshalReturnedValues(cdrStream& _n)
{
  result >>= _n;

}

void _0RL_cd_efe87cde4422e9bd_90000000::unmarshalReturnedValues(cdrStream& _n)
{
  (::CORBA::Short&)result <<= _n;

}

const char* const _0RL_cd_efe87cde4422e9bd_90000000::_user_exns[] = {
  0
};

// Local call call-back function.
static void
_0RL_lcfn_efe87cde4422e9bd_a0000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_efe87cde4422e9bd_90000000* tcd = (_0RL_cd_efe87cde4422e9bd_90000000*)cd;
  P2P::_impl_cs* impl = (P2P::_impl_cs*) svnt->_ptrToInterface(P2P::cs::_PD_repoId);
  tcd->result = impl->pedirAmistad(tcd->arg_0, tcd->arg_1);


}

::CORBA::Short P2P::_objref_cs::pedirAmistad(const char* correo1, const char* correo2)
{
  _0RL_cd_efe87cde4422e9bd_90000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_a0000000, "pedirAmistad", 13);
  _call_desc.arg_0 = correo1;
  _call_desc.arg_1 = correo2;

  _invoke(_call_desc);
  return _call_desc.result;


}


//
// Code for P2P::cs::logueo

// Proxy call descriptor class. Mangled signature:
//  _cP2P_mamigos_i_cstring_i_cstring
class _0RL_cd_efe87cde4422e9bd_b0000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_efe87cde4422e9bd_b0000000(LocalCallFn lcfn, const char* op_, size_t oplen, _CORBA_Boolean upcall=0)
    : omniCallDescriptor(lcfn, op_, oplen, 0, _user_exns, 0, upcall)
  {
    
  }
  
  void marshalArguments(cdrStream&);
  void unmarshalArguments(cdrStream&);

  void unmarshalReturnedValues(cdrStream&);
  void marshalReturnedValues(cdrStream&);
  
  
  static const char* const _user_exns[];

  ::CORBA::String_var arg_0_;
  const char* arg_0;
  ::CORBA::String_var arg_1_;
  const char* arg_1;
  P2P::amigos_var result;
};

void _0RL_cd_efe87cde4422e9bd_b0000000::marshalArguments(cdrStream& _n)
{
  _n.marshalString(arg_0,0);
  _n.marshalString(arg_1,0);

}

void _0RL_cd_efe87cde4422e9bd_b0000000::unmarshalArguments(cdrStream& _n)
{
  arg_0_ = _n.unmarshalString(0);
  arg_0 = arg_0_.in();
  arg_1_ = _n.unmarshalString(0);
  arg_1 = arg_1_.in();

}

void _0RL_cd_efe87cde4422e9bd_b0000000::marshalReturnedValues(cdrStream& _n)
{
  (const P2P::amigos&) result >>= _n;

}

void _0RL_cd_efe87cde4422e9bd_b0000000::unmarshalReturnedValues(cdrStream& _n)
{
  result = new P2P::amigos;
  (P2P::amigos&)result <<= _n;

}

const char* const _0RL_cd_efe87cde4422e9bd_b0000000::_user_exns[] = {
  0
};

// Local call call-back function.
static void
_0RL_lcfn_efe87cde4422e9bd_c0000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_efe87cde4422e9bd_b0000000* tcd = (_0RL_cd_efe87cde4422e9bd_b0000000*)cd;
  P2P::_impl_cs* impl = (P2P::_impl_cs*) svnt->_ptrToInterface(P2P::cs::_PD_repoId);
  tcd->result = impl->logueo(tcd->arg_0, tcd->arg_1);


}

P2P::amigos* P2P::_objref_cs::logueo(const char* correo, const char* pass)
{
  _0RL_cd_efe87cde4422e9bd_b0000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_c0000000, "logueo", 7);
  _call_desc.arg_0 = correo;
  _call_desc.arg_1 = pass;

  _invoke(_call_desc);
  return _call_desc.result._retn();


}


//
// Code for P2P::cs::registro

// Proxy call descriptor class. Mangled signature:
//  _cshort_i_cstring_i_cstring_i_cstring
class _0RL_cd_efe87cde4422e9bd_d0000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_efe87cde4422e9bd_d0000000(LocalCallFn lcfn, const char* op_, size_t oplen, _CORBA_Boolean upcall=0)
    : omniCallDescriptor(lcfn, op_, oplen, 0, _user_exns, 0, upcall)
  {
    
  }
  
  void marshalArguments(cdrStream&);
  void unmarshalArguments(cdrStream&);

  void unmarshalReturnedValues(cdrStream&);
  void marshalReturnedValues(cdrStream&);
  
  
  static const char* const _user_exns[];

  ::CORBA::String_var arg_0_;
  const char* arg_0;
  ::CORBA::String_var arg_1_;
  const char* arg_1;
  ::CORBA::String_var arg_2_;
  const char* arg_2;
  ::CORBA::Short result;
};

void _0RL_cd_efe87cde4422e9bd_d0000000::marshalArguments(cdrStream& _n)
{
  _n.marshalString(arg_0,0);
  _n.marshalString(arg_1,0);
  _n.marshalString(arg_2,0);

}

void _0RL_cd_efe87cde4422e9bd_d0000000::unmarshalArguments(cdrStream& _n)
{
  arg_0_ = _n.unmarshalString(0);
  arg_0 = arg_0_.in();
  arg_1_ = _n.unmarshalString(0);
  arg_1 = arg_1_.in();
  arg_2_ = _n.unmarshalString(0);
  arg_2 = arg_2_.in();

}

void _0RL_cd_efe87cde4422e9bd_d0000000::marshalReturnedValues(cdrStream& _n)
{
  result >>= _n;

}

void _0RL_cd_efe87cde4422e9bd_d0000000::unmarshalReturnedValues(cdrStream& _n)
{
  (::CORBA::Short&)result <<= _n;

}

const char* const _0RL_cd_efe87cde4422e9bd_d0000000::_user_exns[] = {
  0
};

// Local call call-back function.
static void
_0RL_lcfn_efe87cde4422e9bd_e0000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_efe87cde4422e9bd_d0000000* tcd = (_0RL_cd_efe87cde4422e9bd_d0000000*)cd;
  P2P::_impl_cs* impl = (P2P::_impl_cs*) svnt->_ptrToInterface(P2P::cs::_PD_repoId);
  tcd->result = impl->registro(tcd->arg_0, tcd->arg_1, tcd->arg_2);


}

::CORBA::Short P2P::_objref_cs::registro(const char* correo, const char* pass, const char* nombre)
{
  _0RL_cd_efe87cde4422e9bd_d0000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_e0000000, "registro", 9);
  _call_desc.arg_0 = correo;
  _call_desc.arg_1 = pass;
  _call_desc.arg_2 = nombre;

  _invoke(_call_desc);
  return _call_desc.result;


}


//
// Code for P2P::cs::desregistro

// Proxy call descriptor class. Mangled signature:
//  _cboolean_i_cstring
class _0RL_cd_efe87cde4422e9bd_f0000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_efe87cde4422e9bd_f0000000(LocalCallFn lcfn, const char* op_, size_t oplen, _CORBA_Boolean upcall=0)
    : omniCallDescriptor(lcfn, op_, oplen, 0, _user_exns, 0, upcall)
  {
    
  }
  
  void marshalArguments(cdrStream&);
  void unmarshalArguments(cdrStream&);

  void unmarshalReturnedValues(cdrStream&);
  void marshalReturnedValues(cdrStream&);
  
  
  static const char* const _user_exns[];

  ::CORBA::String_var arg_0_;
  const char* arg_0;
  ::CORBA::Boolean result;
};

void _0RL_cd_efe87cde4422e9bd_f0000000::marshalArguments(cdrStream& _n)
{
  _n.marshalString(arg_0,0);

}

void _0RL_cd_efe87cde4422e9bd_f0000000::unmarshalArguments(cdrStream& _n)
{
  arg_0_ = _n.unmarshalString(0);
  arg_0 = arg_0_.in();

}

void _0RL_cd_efe87cde4422e9bd_f0000000::marshalReturnedValues(cdrStream& _n)
{
  _n.marshalBoolean(result);

}

void _0RL_cd_efe87cde4422e9bd_f0000000::unmarshalReturnedValues(cdrStream& _n)
{
  result = _n.unmarshalBoolean();

}

const char* const _0RL_cd_efe87cde4422e9bd_f0000000::_user_exns[] = {
  0
};

// Local call call-back function.
static void
_0RL_lcfn_efe87cde4422e9bd_01000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_efe87cde4422e9bd_f0000000* tcd = (_0RL_cd_efe87cde4422e9bd_f0000000*)cd;
  P2P::_impl_cs* impl = (P2P::_impl_cs*) svnt->_ptrToInterface(P2P::cs::_PD_repoId);
  tcd->result = impl->desregistro(tcd->arg_0);


}

::CORBA::Boolean P2P::_objref_cs::desregistro(const char* correo)
{
  _0RL_cd_efe87cde4422e9bd_f0000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_01000000, "desregistro", 12);
  _call_desc.arg_0 = correo;

  _invoke(_call_desc);
  return _call_desc.result;


}


//
// Code for P2P::cs::modPass

// Local call call-back function.
static void
_0RL_lcfn_efe87cde4422e9bd_11000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_efe87cde4422e9bd_d0000000* tcd = (_0RL_cd_efe87cde4422e9bd_d0000000*)cd;
  P2P::_impl_cs* impl = (P2P::_impl_cs*) svnt->_ptrToInterface(P2P::cs::_PD_repoId);
  tcd->result = impl->modPass(tcd->arg_0, tcd->arg_1, tcd->arg_2);


}

::CORBA::Short P2P::_objref_cs::modPass(const char* correo, const char* pass1, const char* pass2)
{
  _0RL_cd_efe87cde4422e9bd_d0000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_11000000, "modPass", 8);
  _call_desc.arg_0 = correo;
  _call_desc.arg_1 = pass1;
  _call_desc.arg_2 = pass2;

  _invoke(_call_desc);
  return _call_desc.result;


}


//
// Code for P2P::cs::deslogueo

// Local call call-back function.
static void
_0RL_lcfn_efe87cde4422e9bd_21000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_efe87cde4422e9bd_f0000000* tcd = (_0RL_cd_efe87cde4422e9bd_f0000000*)cd;
  P2P::_impl_cs* impl = (P2P::_impl_cs*) svnt->_ptrToInterface(P2P::cs::_PD_repoId);
  tcd->result = impl->deslogueo(tcd->arg_0);


}

::CORBA::Boolean P2P::_objref_cs::deslogueo(const char* correo)
{
  _0RL_cd_efe87cde4422e9bd_f0000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_21000000, "deslogueo", 10);
  _call_desc.arg_0 = correo;

  _invoke(_call_desc);
  return _call_desc.result;


}


//
// Code for P2P::cs::aceptarAmistad

// Proxy call descriptor class. Mangled signature:
//  _cboolean_i_cstring_i_cstring
class _0RL_cd_efe87cde4422e9bd_31000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_efe87cde4422e9bd_31000000(LocalCallFn lcfn, const char* op_, size_t oplen, _CORBA_Boolean upcall=0)
    : omniCallDescriptor(lcfn, op_, oplen, 0, _user_exns, 0, upcall)
  {
    
  }
  
  void marshalArguments(cdrStream&);
  void unmarshalArguments(cdrStream&);

  void unmarshalReturnedValues(cdrStream&);
  void marshalReturnedValues(cdrStream&);
  
  
  static const char* const _user_exns[];

  ::CORBA::String_var arg_0_;
  const char* arg_0;
  ::CORBA::String_var arg_1_;
  const char* arg_1;
  ::CORBA::Boolean result;
};

void _0RL_cd_efe87cde4422e9bd_31000000::marshalArguments(cdrStream& _n)
{
  _n.marshalString(arg_0,0);
  _n.marshalString(arg_1,0);

}

void _0RL_cd_efe87cde4422e9bd_31000000::unmarshalArguments(cdrStream& _n)
{
  arg_0_ = _n.unmarshalString(0);
  arg_0 = arg_0_.in();
  arg_1_ = _n.unmarshalString(0);
  arg_1 = arg_1_.in();

}

void _0RL_cd_efe87cde4422e9bd_31000000::marshalReturnedValues(cdrStream& _n)
{
  _n.marshalBoolean(result);

}

void _0RL_cd_efe87cde4422e9bd_31000000::unmarshalReturnedValues(cdrStream& _n)
{
  result = _n.unmarshalBoolean();

}

const char* const _0RL_cd_efe87cde4422e9bd_31000000::_user_exns[] = {
  0
};

// Local call call-back function.
static void
_0RL_lcfn_efe87cde4422e9bd_41000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_efe87cde4422e9bd_31000000* tcd = (_0RL_cd_efe87cde4422e9bd_31000000*)cd;
  P2P::_impl_cs* impl = (P2P::_impl_cs*) svnt->_ptrToInterface(P2P::cs::_PD_repoId);
  tcd->result = impl->aceptarAmistad(tcd->arg_0, tcd->arg_1);


}

::CORBA::Boolean P2P::_objref_cs::aceptarAmistad(const char* correo1, const char* correo2)
{
  _0RL_cd_efe87cde4422e9bd_31000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_41000000, "aceptarAmistad", 15);
  _call_desc.arg_0 = correo1;
  _call_desc.arg_1 = correo2;

  _invoke(_call_desc);
  return _call_desc.result;


}


//
// Code for P2P::cs::buscaAmigos

// Proxy call descriptor class. Mangled signature:
//  _cP2P_mbuscar_i_cstring_i_cstring
class _0RL_cd_efe87cde4422e9bd_51000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_efe87cde4422e9bd_51000000(LocalCallFn lcfn, const char* op_, size_t oplen, _CORBA_Boolean upcall=0)
    : omniCallDescriptor(lcfn, op_, oplen, 0, _user_exns, 0, upcall)
  {
    
  }
  
  void marshalArguments(cdrStream&);
  void unmarshalArguments(cdrStream&);

  void unmarshalReturnedValues(cdrStream&);
  void marshalReturnedValues(cdrStream&);
  
  
  static const char* const _user_exns[];

  ::CORBA::String_var arg_0_;
  const char* arg_0;
  ::CORBA::String_var arg_1_;
  const char* arg_1;
  P2P::buscar_var result;
};

void _0RL_cd_efe87cde4422e9bd_51000000::marshalArguments(cdrStream& _n)
{
  _n.marshalString(arg_0,0);
  _n.marshalString(arg_1,0);

}

void _0RL_cd_efe87cde4422e9bd_51000000::unmarshalArguments(cdrStream& _n)
{
  arg_0_ = _n.unmarshalString(0);
  arg_0 = arg_0_.in();
  arg_1_ = _n.unmarshalString(0);
  arg_1 = arg_1_.in();

}

void _0RL_cd_efe87cde4422e9bd_51000000::marshalReturnedValues(cdrStream& _n)
{
  (const P2P::buscar&) result >>= _n;

}

void _0RL_cd_efe87cde4422e9bd_51000000::unmarshalReturnedValues(cdrStream& _n)
{
  result = new P2P::buscar;
  (P2P::buscar&)result <<= _n;

}

const char* const _0RL_cd_efe87cde4422e9bd_51000000::_user_exns[] = {
  0
};

// Local call call-back function.
static void
_0RL_lcfn_efe87cde4422e9bd_61000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_efe87cde4422e9bd_51000000* tcd = (_0RL_cd_efe87cde4422e9bd_51000000*)cd;
  P2P::_impl_cs* impl = (P2P::_impl_cs*) svnt->_ptrToInterface(P2P::cs::_PD_repoId);
  tcd->result = impl->buscaAmigos(tcd->arg_0, tcd->arg_1);


}

P2P::buscar* P2P::_objref_cs::buscaAmigos(const char* nombre, const char* correo)
{
  _0RL_cd_efe87cde4422e9bd_51000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_61000000, "buscaAmigos", 12);
  _call_desc.arg_0 = nombre;
  _call_desc.arg_1 = correo;

  _invoke(_call_desc);
  return _call_desc.result._retn();


}


//
// Code for P2P::cs::noAmistad

// Local call call-back function.
static void
_0RL_lcfn_efe87cde4422e9bd_71000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_efe87cde4422e9bd_31000000* tcd = (_0RL_cd_efe87cde4422e9bd_31000000*)cd;
  P2P::_impl_cs* impl = (P2P::_impl_cs*) svnt->_ptrToInterface(P2P::cs::_PD_repoId);
  tcd->result = impl->noAmistad(tcd->arg_0, tcd->arg_1);


}

::CORBA::Boolean P2P::_objref_cs::noAmistad(const char* correo1, const char* correo2)
{
  _0RL_cd_efe87cde4422e9bd_31000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_71000000, "noAmistad", 10);
  _call_desc.arg_0 = correo1;
  _call_desc.arg_1 = correo2;

  _invoke(_call_desc);
  return _call_desc.result;


}


//
// Code for P2P::cs::initAmistad

// Local call call-back function.
static void
_0RL_lcfn_efe87cde4422e9bd_81000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_efe87cde4422e9bd_20000000* tcd = (_0RL_cd_efe87cde4422e9bd_20000000*)cd;
  P2P::_impl_cs* impl = (P2P::_impl_cs*) svnt->_ptrToInterface(P2P::cs::_PD_repoId);
  impl->initAmistad(tcd->arg_0);


}

void P2P::_objref_cs::initAmistad(const char* correo1)
{
  _0RL_cd_efe87cde4422e9bd_20000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_81000000, "initAmistad", 12);
  _call_desc.arg_0 = correo1;

  _invoke(_call_desc);



}

P2P::_pof_cs::~_pof_cs() {}


omniObjRef*
P2P::_pof_cs::newObjRef(omniIOR* ior, omniIdentity* id)
{
  return new ::P2P::_objref_cs(ior, id);
}


::CORBA::Boolean
P2P::_pof_cs::is_a(const char* id) const
{
  if (omni::ptrStrMatch(id, ::P2P::cs::_PD_repoId))
    return 1;
  
  return 0;
}

const P2P::_pof_cs _the_pof_P2P_mcs;

P2P::_impl_cs::~_impl_cs() {}


::CORBA::Boolean
P2P::_impl_cs::_dispatch(omniCallHandle& _handle)
{
  const char* op = _handle.operation_name();

  if (omni::strMatch(op, "pedirAmistad")) {

    _0RL_cd_efe87cde4422e9bd_90000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_a0000000, "pedirAmistad", 13, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if (omni::strMatch(op, "logueo")) {

    _0RL_cd_efe87cde4422e9bd_b0000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_c0000000, "logueo", 7, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if (omni::strMatch(op, "registro")) {

    _0RL_cd_efe87cde4422e9bd_d0000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_e0000000, "registro", 9, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if (omni::strMatch(op, "desregistro")) {

    _0RL_cd_efe87cde4422e9bd_f0000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_01000000, "desregistro", 12, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if (omni::strMatch(op, "modPass")) {

    _0RL_cd_efe87cde4422e9bd_d0000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_11000000, "modPass", 8, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if (omni::strMatch(op, "deslogueo")) {

    _0RL_cd_efe87cde4422e9bd_f0000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_21000000, "deslogueo", 10, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if (omni::strMatch(op, "aceptarAmistad")) {

    _0RL_cd_efe87cde4422e9bd_31000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_41000000, "aceptarAmistad", 15, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if (omni::strMatch(op, "buscaAmigos")) {

    _0RL_cd_efe87cde4422e9bd_51000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_61000000, "buscaAmigos", 12, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if (omni::strMatch(op, "noAmistad")) {

    _0RL_cd_efe87cde4422e9bd_31000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_71000000, "noAmistad", 10, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if (omni::strMatch(op, "initAmistad")) {

    _0RL_cd_efe87cde4422e9bd_20000000 _call_desc(_0RL_lcfn_efe87cde4422e9bd_81000000, "initAmistad", 12, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }


  return 0;
}

void*
P2P::_impl_cs::_ptrToInterface(const char* id)
{
  if (id == ::P2P::cs::_PD_repoId)
    return (::P2P::_impl_cs*) this;
  
  if (id == ::CORBA::Object::_PD_repoId)
    return (void*) 1;

  if (omni::strMatch(id, ::P2P::cs::_PD_repoId))
    return (::P2P::_impl_cs*) this;
  
  if (omni::strMatch(id, ::CORBA::Object::_PD_repoId))
    return (void*) 1;
  return 0;
}

const char*
P2P::_impl_cs::_mostDerivedRepoId()
{
  return ::P2P::cs::_PD_repoId;
}

POA_P2P::cc::~cc() {}

POA_P2P::sc::~sc() {}

POA_P2P::cs::~cs() {}

