/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:03:06 by imutavdz          #+#    #+#             */
/*   Updated: 2025/03/16 18:52:52 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void print(int array[], int size)
{
	int i = 0;

	while (i < size)
		printf("%d", array[i++]);
	printf("\n");
}

int main()
{
	int i = 0;
	int arr[] = {5, 3, 6, 2, 10, 100, 41, 411, 1232, 92922, 323, 23};
	int len = sizeof(arr)/sizeof(arr[0]);

	radix_sort(arr, len);
	printf("sorted array: ");
	while (i < len)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	return (0);
}
