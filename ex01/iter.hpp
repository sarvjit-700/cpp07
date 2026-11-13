/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 10:48:34 by ssukhija          #+#    #+#             */
/*   Updated: 2026/10/26 10:48:34 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename Func>
void iter(T *arr, const std::size_t len, Func fn)
{
    std::size_t i;

    i = 0;
    while (i < len)
    {
        fn(arr[i]);
        i++;
    }
}

#endif
