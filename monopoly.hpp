#ifndef MONOPOLY_H
#define MONOPOLY_H

#include "linkedlist.hpp"
#include <string>
#include <iostream>
#include <stdexcept>

class MonopolyBoard
{
public:
    struct Property
    {
        int id;
        std::string name;
        int price;
        int rent;
        int landedCount;
        Property(int id, std::string name, int price, int rent) : id(id), name(name), price(price), rent(rent), landedCount(0) {}
    };

    MonopolyBoard()
    {
        board.append(Property(0, "Go", 0, 0));
        board.append(Property(1, "Mediterranean Avenue", 60, 2));
        board.append(Property(2, "Community Chest", 0, 0));
        board.append(Property(3, "Baltic Avenue", 60, 4));
        board.append(Property(4, "Income Tax", 0, 0));
        board.append(Property(5, "Reading Railroad", 200, 25));
        board.append(Property(6, "Oriental Avenue", 100, 6));
        board.append(Property(7, "Chance", 0, 0));
        board.append(Property(8, "Vermont Avenue", 100, 6));
        board.append(Property(9, "Connecticut Avenue", 120, 8));
        board.append(Property(10, "Jail", 0, 0));
        board.append(Property(11, "St. Charles Place", 140, 10));
        board.append(Property(12, "Electric Company", 150, 0));
        board.append(Property(13, "States Avenue", 140, 10));
        board.append(Property(14, "Virginia Avenue", 160, 12));
        board.append(Property(15, "Pennsylvania Railroad", 200, 25));
        board.append(Property(16, "St. James Place", 180, 14));
        board.append(Property(17, "Community Chest", 0, 0));
        board.append(Property(18, "Tennessee Avenue", 180, 14));
        board.append(Property(19, "New York Avenue", 200, 16));
        board.append(Property(20, "Free Parking", 0, 0));
        board.append(Property(21, "Kentucky Avenue", 220, 18));
        board.append(Property(22, "Chance", 0, 0));
        board.append(Property(23, "Indiana Avenue", 220, 18));
        board.append(Property(24, "Illinois Avenue", 240, 20));
        board.append(Property(25, "B. & O. Railroad", 200, 25));
        board.append(Property(26, "Atlantic Avenue", 260, 22));
        board.append(Property(27, "Ventnor Avenue", 260, 22));
        board.append(Property(28, "Water Works", 150, 0));
        board.append(Property(29, "Marvin Gardens", 280, 24));
        board.append(Property(30, "Go To Jail", 0, 0));
        board.append(Property(31, "Pacific Avenue", 300, 26));
        board.append(Property(32, "North Carolina Avenue", 300, 26));
        board.append(Property(33, "Community Chest", 0, 0));
        board.append(Property(34, "Pennsylvania Avenue", 320, 28));
        board.append(Property(35, "Short Line", 200, 25));
        board.append(Property(36, "Chance", 0, 0));
        board.append(Property(37, "Park Place", 350, 35));
        board.append(Property(38, "Luxury Tax", 0, 0));
        board.append(Property(39, "Boardwalk", 400, 50));
    }

    void displayBoard() const
    {
        for (int i = 0; i < board.size(); ++i)
        {
            const Property &property = board.get(i);
            std::cout << property.name << " - Price: $" << property.price << ", Rent: $" << property.rent << ", Landed Count: " << property.landedCount << std::endl;
        }
    }

    const Property &getProperty(int index) const
    {
        return board.get(index);
    }

    const Property &getProperty(const std::string &name) const
    {
        for (int i = 0; i < board.size(); ++i)
        {
            const Property &property = board.get(i);
            if (property.name == name)
            {
                return property;
            }
        }
        throw std::invalid_argument("Property not found");
    }

    void incrementLandedCount(int index)
    {
        Property &property = board.get(index);
        property.landedCount++;
    }

    void incrementLandedCount(const std::string &name)
    {
        for (int i = 0; i < board.size(); ++i)
        {
            Property &property = board.get(i);
            if (property.name == name)
            {
                property.landedCount++;
                return;
            }
        }
        throw std::invalid_argument("Property not found");
    }

    int getLandedCount(int index) const
    {
        return board.get(index).landedCount;
    }

    int getLandedCount(const std::string &name) const
    {
        for (int i = 0; i < board.size(); ++i)
        {
            const Property &property = board.get(i);
            if (property.name == name)
            {
                return property.landedCount;
            }
        }
        throw std::invalid_argument("Property not found");
    }

    int size() const
    {
        return board.size();
    }

    int diceRoll() const
    {
        return rand() % 6 + 1;
    }

private:
    CircularDoublyLinkedList<Property> board;
};

#endif // MONOPOLY_H