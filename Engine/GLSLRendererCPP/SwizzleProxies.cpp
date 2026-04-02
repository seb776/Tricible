//#include "../Tools/Macros.hpp"
//#include "SwizzleProxies.hpp"
//#include "vec2.hpp"
//#include "vec3.hpp"
//#include "vec4.hpp"
//
//// ==================== swizzle1 ====================
//template<typename VecType, typename ScalarType, int A>
//TRICIBLE_FORCEINLINE swizzle1<VecType, ScalarType, A>::swizzle1(VecType& v)
//    : vec(&v) {}
//
//template<typename VecType, typename ScalarType, int A>
//TRICIBLE_FORCEINLINE swizzle1<VecType, ScalarType, A>::operator ScalarType() const
//{
//    return (*vec)[A];
//}
//
//template<typename VecType, typename ScalarType, int A>
//TRICIBLE_FORCEINLINE typename swizzle1<VecType, ScalarType, A>::self&
//swizzle1<VecType, ScalarType, A>::operator=(const ScalarType& rhs)
//{
//    (*vec)[A] = rhs;
//    return *this;
//}
//
//template<typename VecType, typename ScalarType, int A>
//TRICIBLE_FORCEINLINE typename swizzle1<VecType, ScalarType, A>::self&
//swizzle1<VecType, ScalarType, A>::operator+=(const ScalarType& rhs)
//{
//    (*vec)[A] += rhs;
//    return *this;
//}
//
//template<typename VecType, typename ScalarType, int A>
//TRICIBLE_FORCEINLINE typename swizzle1<VecType, ScalarType, A>::self&
//swizzle1<VecType, ScalarType, A>::operator-=(const ScalarType& rhs)
//{
//    (*vec)[A] -= rhs;
//    return *this;
//}
//
//template<typename VecType, typename ScalarType, int A>
//TRICIBLE_FORCEINLINE typename swizzle1<VecType, ScalarType, A>::self&
//swizzle1<VecType, ScalarType, A>::operator*=(const ScalarType& rhs)
//{
//    (*vec)[A] *= rhs;
//    return *this;
//}
//
//template<typename VecType, typename ScalarType, int A>
//TRICIBLE_FORCEINLINE typename swizzle1<VecType, ScalarType, A>::self&
//swizzle1<VecType, ScalarType, A>::operator/=(const ScalarType& rhs)
//{
//    (*vec)[A] /= rhs;
//    return *this;
//}
//
//// ==================== swizzle2 ====================
//template<typename VecType, typename ScalarType, int A, int B>
//TRICIBLE_FORCEINLINE swizzle2<VecType, ScalarType, A, B>::swizzle2(VecType& v)
//    : vec(&v) {}
//
//template<typename VecType, typename ScalarType, int A, int B>
//TRICIBLE_FORCEINLINE swizzle2<VecType, ScalarType, A, B>::operator vec2() const
//{
//    return vec2{ (*vec)[A], (*vec)[B] };
//}
//
//template<typename VecType, typename ScalarType, int A, int B>
//TRICIBLE_FORCEINLINE typename swizzle2<VecType, ScalarType, A, B>::self&
//swizzle2<VecType, ScalarType, A, B>::operator=(const vec2& rhs)
//{
//    auto tmp = rhs;
//    (*vec)[A] = tmp[0];
//    (*vec)[B] = tmp[1];
//    return *this;
//}
//
//template<typename VecType, typename ScalarType, int A, int B>
//TRICIBLE_FORCEINLINE typename swizzle2<VecType, ScalarType, A, B>::self&
//swizzle2<VecType, ScalarType, A, B>::operator+=(const vec2& rhs)
//{
//    auto tmp = rhs;
//    (*vec)[A] += tmp[0];
//    (*vec)[B] += tmp[1];
//    return *this;
//}
//
//template<typename VecType, typename ScalarType, int A, int B>
//TRICIBLE_FORCEINLINE typename swizzle2<VecType, ScalarType, A, B>::self&
//swizzle2<VecType, ScalarType, A, B>::operator-=(const vec2& rhs)
//{
//    auto tmp = rhs;
//    (*vec)[A] -= tmp[0];
//    (*vec)[B] -= tmp[1];
//    return *this;
//}
//
//// ==================== swizzle3 ====================
//template<typename VecType, typename ScalarType, int A, int B, int C>
//TRICIBLE_FORCEINLINE swizzle3<VecType, ScalarType, A, B, C>::swizzle3(VecType& v)
//    : vec(&v) {}
//
//template<typename VecType, typename ScalarType, int A, int B, int C>
//TRICIBLE_FORCEINLINE swizzle3<VecType, ScalarType, A, B, C>::operator vec3() const
//{
//    return vec3{ (*vec)[A], (*vec)[B], (*vec)[C] };
//}
//
//template<typename VecType, typename ScalarType, int A, int B, int C>
//TRICIBLE_FORCEINLINE typename swizzle3<VecType, ScalarType, A, B, C>::self&
//swizzle3<VecType, ScalarType, A, B, C>::operator=(const vec3& rhs)
//{
//    auto tmp = rhs;
//    (*vec)[A] = tmp[0];
//    (*vec)[B] = tmp[1];
//    (*vec)[C] = tmp[2];
//    return *this;
//}
//
//template<typename VecType, typename ScalarType, int A, int B, int C>
//TRICIBLE_FORCEINLINE typename swizzle3<VecType, ScalarType, A, B, C>::self&
//swizzle3<VecType, ScalarType, A, B, C>::operator+=(const vec3& rhs)
//{
//    auto tmp = rhs;
//    (*vec)[A] += tmp[0];
//    (*vec)[B] += tmp[1];
//    (*vec)[C] += tmp[2];
//    return *this;
//}
//
//template<typename VecType, typename ScalarType, int A, int B, int C>
//TRICIBLE_FORCEINLINE typename swizzle3<VecType, ScalarType, A, B, C>::self&
//swizzle3<VecType, ScalarType, A, B, C>::operator-=(const vec3& rhs)
//{
//    auto tmp = rhs;
//    (*vec)[A] -= tmp[0];
//    (*vec)[B] -= tmp[1];
//    (*vec)[C] -= tmp[2];
//    return *this;
//}
//
//// ==================== swizzle4 ====================
//template<typename VecType, typename ScalarType, int A, int B, int C, int D>
//TRICIBLE_FORCEINLINE swizzle4<VecType, ScalarType, A, B, C, D>::swizzle4(VecType& v)
//    : vec(&v) {}
//
//template<typename VecType, typename ScalarType, int A, int B, int C, int D>
//TRICIBLE_FORCEINLINE swizzle4<VecType, ScalarType, A, B, C, D>::operator vec4() const
//{
//    return vec4{ (*vec)[A], (*vec)[B], (*vec)[C], (*vec)[D] };
//}
//
//template<typename VecType, typename ScalarType, int A, int B, int C, int D>
//TRICIBLE_FORCEINLINE typename swizzle4<VecType, ScalarType, A, B, C, D>::self&
//swizzle4<VecType, ScalarType, A, B, C, D>::operator=(const vec4& rhs)
//{
//    auto tmp = rhs;
//    (*vec)[A] = tmp[0];
//    (*vec)[B] = tmp[1];
//    (*vec)[C] = tmp[2];
//    (*vec)[D] = tmp[3];
//    return *this;
//}
//
//template<typename VecType, typename ScalarType, int A, int B, int C, int D>
//TRICIBLE_FORCEINLINE typename swizzle4<VecType, ScalarType, A, B, C, D>::self&
//swizzle4<VecType, ScalarType, A, B, C, D>::operator+=(const vec4& rhs)
//{
//    auto tmp = rhs;
//    (*vec)[A] += tmp[0];
//    (*vec)[B] += tmp[1];
//    (*vec)[C] += tmp[2];
//    (*vec)[D] += tmp[3];
//    return *this;
//}
//
//template<typename VecType, typename ScalarType, int A, int B, int C, int D>
//TRICIBLE_FORCEINLINE typename swizzle4<VecType, ScalarType, A, B, C, D>::self&
//swizzle4<VecType, ScalarType, A, B, C, D>::operator-=(const vec4& rhs)
//{
//    auto tmp = rhs;
//    (*vec)[A] -= tmp[0];
//    (*vec)[B] -= tmp[1];
//    (*vec)[C] -= tmp[2];
//    (*vec)[D] -= tmp[3];
//    return *this;
//}