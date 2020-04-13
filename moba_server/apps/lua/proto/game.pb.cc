// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: game.proto

#include "game.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
class GuestLoginReqDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<GuestLoginReq> _instance;
} _GuestLoginReq_default_instance_;
static void InitDefaultsscc_info_GuestLoginReq_game_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_GuestLoginReq_default_instance_;
    new (ptr) ::GuestLoginReq();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::GuestLoginReq::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_GuestLoginReq_game_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_GuestLoginReq_game_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_game_2eproto[1];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_game_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_game_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_game_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::GuestLoginReq, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::GuestLoginReq, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::GuestLoginReq, guest_key_),
  0,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 6, sizeof(::GuestLoginReq)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_GuestLoginReq_default_instance_),
};

const char descriptor_table_protodef_game_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\ngame.proto\"\"\n\rGuestLoginReq\022\021\n\tguest_k"
  "ey\030\001 \002(\t*;\n\005Stype\022\021\n\rINVALID_STYPE\020\000\022\010\n\004"
  "Auth\020\001\022\n\n\006System\020\002\022\t\n\005Logic\020\003**\n\003Cmd\022\017\n\013"
  "INVALID_CMD\020\000\022\022\n\016eGuestLoginReq\020\001"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_game_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_game_2eproto_sccs[1] = {
  &scc_info_GuestLoginReq_game_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_game_2eproto_once;
static bool descriptor_table_game_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_game_2eproto = {
  &descriptor_table_game_2eproto_initialized, descriptor_table_protodef_game_2eproto, "game.proto", 153,
  &descriptor_table_game_2eproto_once, descriptor_table_game_2eproto_sccs, descriptor_table_game_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_game_2eproto::offsets,
  file_level_metadata_game_2eproto, 1, file_level_enum_descriptors_game_2eproto, file_level_service_descriptors_game_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_game_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_game_2eproto), true);
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Stype_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_game_2eproto);
  return file_level_enum_descriptors_game_2eproto[0];
}
bool Stype_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Cmd_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_game_2eproto);
  return file_level_enum_descriptors_game_2eproto[1];
}
bool Cmd_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}


// ===================================================================

void GuestLoginReq::InitAsDefaultInstance() {
}
class GuestLoginReq::_Internal {
 public:
  using HasBits = decltype(std::declval<GuestLoginReq>()._has_bits_);
  static void set_has_guest_key(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

GuestLoginReq::GuestLoginReq()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:GuestLoginReq)
}
GuestLoginReq::GuestLoginReq(const GuestLoginReq& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  guest_key_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_guest_key()) {
    guest_key_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.guest_key_);
  }
  // @@protoc_insertion_point(copy_constructor:GuestLoginReq)
}

void GuestLoginReq::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_GuestLoginReq_game_2eproto.base);
  guest_key_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

GuestLoginReq::~GuestLoginReq() {
  // @@protoc_insertion_point(destructor:GuestLoginReq)
  SharedDtor();
}

void GuestLoginReq::SharedDtor() {
  guest_key_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void GuestLoginReq::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const GuestLoginReq& GuestLoginReq::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_GuestLoginReq_game_2eproto.base);
  return *internal_default_instance();
}


void GuestLoginReq::Clear() {
// @@protoc_insertion_point(message_clear_start:GuestLoginReq)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    guest_key_.ClearNonDefaultToEmptyNoArena();
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* GuestLoginReq::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // required string guest_key = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_guest_key();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "GuestLoginReq.guest_key");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* GuestLoginReq::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:GuestLoginReq)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required string guest_key = 1;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_guest_key().data(), static_cast<int>(this->_internal_guest_key().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "GuestLoginReq.guest_key");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_guest_key(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:GuestLoginReq)
  return target;
}

size_t GuestLoginReq::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:GuestLoginReq)
  size_t total_size = 0;

  // required string guest_key = 1;
  if (_internal_has_guest_key()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_guest_key());
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void GuestLoginReq::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:GuestLoginReq)
  GOOGLE_DCHECK_NE(&from, this);
  const GuestLoginReq* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<GuestLoginReq>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:GuestLoginReq)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:GuestLoginReq)
    MergeFrom(*source);
  }
}

void GuestLoginReq::MergeFrom(const GuestLoginReq& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:GuestLoginReq)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_guest_key()) {
    _has_bits_[0] |= 0x00000001u;
    guest_key_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.guest_key_);
  }
}

void GuestLoginReq::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:GuestLoginReq)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GuestLoginReq::CopyFrom(const GuestLoginReq& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:GuestLoginReq)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GuestLoginReq::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;
  return true;
}

void GuestLoginReq::InternalSwap(GuestLoginReq* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  guest_key_.Swap(&other->guest_key_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
}

::PROTOBUF_NAMESPACE_ID::Metadata GuestLoginReq::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::GuestLoginReq* Arena::CreateMaybeMessage< ::GuestLoginReq >(Arena* arena) {
  return Arena::CreateInternal< ::GuestLoginReq >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
