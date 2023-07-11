#pragma once

#include <type_traits>

namespace dirty_hacks
{

    template <class T>
    using remove_cvref_t = typename std::remove_cv_t<std::remove_reference_t<T>>;

    template <class T>
    struct type_identity
    {
        using type = T;
    };
    template <class T>
    using type_identity_t = typename type_identity<T>::type;

    namespace impl
    {

        template <class T>
        struct complete
        {
            template <class U>
            static auto test(U *) -> decltype(sizeof(U), std::true_type{});
            static auto test(...) -> std::false_type;
            using type = decltype(test(static_cast<T *>(nullptr)));
        };

    } // namespace impl

    template <class T>
    struct is_complete : impl::complete<T>::type
    {
    };

} // namespace dirty_hacks

/** Yet another concat implementation. */
#define YA_CAT_IMPL(x, y) x##y
/** Yet another concat. */
#define YA_CAT(x, y) YA_CAT_IMPL(x, y)
/**
 * Init private class member hijacker.
 * @param class_ Class name.
 * @param member Private member to hijack.
 * @param __VA_ARGS__ Member type.
 * @remark All HIJACKERs should appear before any HIJACK.
 */
#define HIJACKER(class_, member, ...)                                                                              \
    namespace dirty_hacks                                                                                          \
    {                                                                                                              \
        namespace hijack                                                                                           \
        {                                                                                                          \
            template <class>                                                                                       \
            struct tag_##member;                                                                                   \
            inline auto get(tag_##member<class_>) -> type_identity_t<__VA_ARGS__> class_::*;                       \
            template <>                                                                                            \
            struct tag_##member<class_>                                                                            \
            {                                                                                                      \
                tag_##member(tag_##member *) {}                                                                    \
                template <class T, class = std::enable_if_t<                                                       \
                                       !is_complete<tag_##member<T>>::value && std::is_base_of<class_, T>::value>> \
                tag_##member(tag_##member<T> *) {}                                                                 \
            };                                                                                                     \
            template <type_identity_t<__VA_ARGS__> class_::*Ptr>                                                   \
            struct YA_CAT(hijack_##member##_, __LINE__)                                                            \
            {                                                                                                      \
                friend auto get(tag_##member<class_>) -> type_identity_t<__VA_ARGS__> class_::* { return Ptr; }    \
            };                                                                                                     \
            template struct YA_CAT(hijack_##member##_, __LINE__)<&class_::member>;                                 \
        }                                                                                                          \
    }
/**
 * Hijack private class member.
 * @param ptr Pointer to class instance.
 * @param member Private member to hijack.
 * @remark All HIJACKs should appear after any HIJACKER.
 */
#define HIJACK(ptr, member)                                                        \
    ((ptr)->*dirty_hacks::hijack::get(                                             \
                 static_cast<std::add_pointer_t<dirty_hacks::hijack::tag_##member< \
                     dirty_hacks::remove_cvref_t<decltype(*ptr)>>>>(nullptr)))