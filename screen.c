/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:13:53 by htalhaou          #+#    #+#             */
/*   Updated: 2022/12/02 16:14:20 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main()
{
system("system_profiler SPDisplaysDataType | grep Resolution | xargs | awk '{print $2}'");
	return (0);
}