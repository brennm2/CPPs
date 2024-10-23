/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:07:27 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/23 14:45:12 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string _Name;
public:
	void	whoAmI(void);
	using	ScavTrap::attack;

	DiamondTrap();
	DiamondTrap(std::string NewName);
	~DiamondTrap();
	DiamondTrap(const DiamondTrap &copy);
	DiamondTrap &operator=(const DiamondTrap &copy);
} ;