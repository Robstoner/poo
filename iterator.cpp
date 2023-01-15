#include <string>
#include <vector>
#include <map>
#include <memory>

#include <iostream>

// IOStream \\

class IOStream {
protected:
    virtual void Print(std::ostream &) const = 0;

    friend std::ostream& operator<<(std::ostream &, const IOStream&);
    friend std::ostream& operator<<(std::ostream &, const IOStream*);

    virtual ~IOStream();
};

std::ostream& operator<<(std::ostream &os, const IOStream &obj) {
    obj.Print(os);
    return os;
}

std::ostream& operator<<(std::ostream &os, const IOStream *obj) {
    obj->Print(os);
    return os;
}

IOStream::~IOStream() = default;


// Clasa Baza Pet \\

class Pet : public IOStream {
protected:
    std::string Name;
    int Age;
public:
    Pet(std::string name, int age);

    Pet(const Pet& rhs);

    Pet& operator=(const Pet& rhs);

    const std::string &GetName() const;

    void SetName(std::string name);

    int GetAge() const;

    void SetAge(int age);

    virtual void MakeSound() const = 0;

    virtual ~Pet();
};


Pet::Pet(std::string name, int age) : Name(std::move(name)), Age(age) {
    // nothing
}

Pet::Pet(const Pet &rhs) : Pet(rhs.Name, rhs.Age) {

}

//Pet::Pet(const Pet &rhs) : Name(rhs.Name), Age(rhs.Age) {
//
//}

Pet &Pet::operator=(const Pet &rhs) {
    if (this != &rhs) {
        Name = rhs.Name;
        Age = rhs.Age;
    }
    return *this;
}

const std::string &Pet::GetName() const {
    return Name;
}

void Pet::SetName(std::string name) {
    Pet::Name = std::move(name);
}

int Pet::GetAge() const {
    return Age;
}

void Pet::SetAge(int age) {
    Pet::Age = age;
}

//void Pet::MakeSound() {
//    std::cout << "Hi I am " << Name << "!\n";
//}

Pet::~Pet() = default;

// Clasa Dog \\

class Dog : public Pet {
    std::string FavoriteFood;

public:
    Dog(std::string name, int age, std::string favoriteFood);

    Dog(const Dog& rhs);

    Dog& operator=(Dog rhs);

    const std::string &GetFavoriteFood() const;

    void SetFavoriteFood(std::string favoriteFood);

    void MakeSound() const override;

    void Print(std::ostream&) const override;

};

Dog::Dog(std::string name, int age, std::string favoriteFood)
        : Pet(std::move(name), age), FavoriteFood(std::move(favoriteFood)) {
    // nothing
}

Dog::Dog(const Dog &rhs) : Pet(rhs.Name, rhs.Age), FavoriteFood(rhs.FavoriteFood) {
    // nothing
}

Dog &Dog::operator=(Dog rhs) {
    Pet::operator=(rhs);
    std::swap(FavoriteFood, rhs.FavoriteFood);

    return *this;
}

const std::string &Dog::GetFavoriteFood() const {
    return FavoriteFood;
}

void Dog::SetFavoriteFood(std::string favoriteFood) {
    Dog::FavoriteFood = std::move(favoriteFood);
}
void Dog::MakeSound() const {
    std::cout << "Woof! Hi I am " << Name << "!\n";
}

void Dog::Print(std::ostream &os) const {
    os << "Dog(" << Name << ", " << Age << ", " << FavoriteFood << ")";
}

// Clasa Cat \\

class Cat : public Pet {
    std::string FavoriteToy;
public:
    Cat(std::string name, int age, std::string favoriteToy);

    const std::string &GetFavoriteToy() const;

    void SetFavoriteToy(std::string favoriteToy);

    void MakeSound() const override;

    void Print(std::ostream &os) const override;
};

Cat::Cat(std::string name, int age, std::string favoriteToy)
        : Pet(std::move(name), age), FavoriteToy(std::move(favoriteToy)) {
    // nothing
}

const std::string &Cat::GetFavoriteToy() const {
    return FavoriteToy;
}

void Cat::SetFavoriteToy(std::string favoriteToy) {
    Cat::FavoriteToy = std::move(favoriteToy);
}

void Cat::MakeSound() const {
    std::cout << "Meow! Hello I am " << GetName() << "!\n";
}

void Cat::Print(std::ostream &os) const {
    os << "Cat(" << Name << ", " << Age << ", " << FavoriteToy << ")";
}

// NoSuchPet \\

class NoSuchPet : public std::exception, public IOStream {
public:
    NoSuchPet() = default;

    const char* what() const noexcept override;

    void Print(std::ostream&) const;
};

const char *NoSuchPet::what() const noexcept {
    return "No such pet";
}

void NoSuchPet::Print(std::ostream &os) const {
    os << this->what();
}

// Impl sablon iterator

template<class T>
class PetShelterIterator {
    std::vector<std::shared_ptr<Pet>>::iterator CurrentPos;
    std::vector<std::shared_ptr<Pet>>::iterator EndPos;

    void SkipToNext() {
        for(; CurrentPos != EndPos; ++CurrentPos)
            if (std::dynamic_pointer_cast<T>(*CurrentPos).get())
                break;
    }

public:
    PetShelterIterator(std::vector<std::shared_ptr<Pet>>::iterator it, std::vector<std::shared_ptr<Pet>>::iterator itEnd)
        : CurrentPos(it), EndPos(itEnd) {
        SkipToNext();
    }

    T& operator*() const {
        return *std::dynamic_pointer_cast<T>(*CurrentPos).get();
    }

    bool operator!=(const PetShelterIterator<T> &petShelterIterator)  const {
        return !(CurrentPos == petShelterIterator.CurrentPos);
    }

    PetShelterIterator<T>& operator++() {
        ++CurrentPos;
        SkipToNext();
        return *this;
    }
};

template<class T>
class PetShelterIteratorContainer {
    std::vector<std::shared_ptr<Pet>> *Vec;
public:
    PetShelterIteratorContainer<T>(std::vector<std::shared_ptr<Pet>> *vec) : Vec(vec) {}

    PetShelterIterator<T> begin() {
        return PetShelterIterator<T>(Vec->begin(), Vec->end());
    }

    PetShelterIterator<T> end() {
        return PetShelterIterator<T>(Vec->end(), Vec->end());
    }
};

// Clasa PetShelter \\

class PetShelter {
    static std::vector<std::shared_ptr<Pet>> Pets; // !!!

public:
    PetShelter() = delete;

    static void AddPet(std::shared_ptr<Pet> pet);
    // ...

    static std::vector<std::shared_ptr<Pet>>& GetPets();

    static std::shared_ptr<Pet> FindPetByName(const std::string& name);

    template<class T>
    static PetShelterIteratorContainer<T> FindAll();
};

template<class T>
PetShelterIteratorContainer<T> PetShelter::FindAll() {
    return PetShelterIteratorContainer<T>(&Pets);
}

std::vector<std::shared_ptr<Pet>> PetShelter::Pets; // !!!

void PetShelter::AddPet(std::shared_ptr<Pet> pet) {
    Pets.push_back(pet);
}

std::vector<std::shared_ptr<Pet>> &PetShelter::GetPets() {
    return PetShelter::Pets;
}

std::shared_ptr<Pet> PetShelter::FindPetByName(const std::string &name) {
    for (auto &pet : PetShelter::Pets)
        if (pet->GetName() == name)
            return pet;

    throw NoSuchPet();
}



class ScoobyDoo : public Dog {
protected:
    ScoobyDoo();
    ScoobyDoo(const ScoobyDoo&) = delete;
    ScoobyDoo& operator=(const ScoobyDoo&) = delete;

public:
    static std::shared_ptr<ScoobyDoo> GetInstance();
};

ScoobyDoo::ScoobyDoo() : Dog("Scooby", 2, "scooby snacks") {
}

std::shared_ptr<ScoobyDoo> ScoobyDoo::GetInstance() {
    static auto scoobyDoo = std::shared_ptr<ScoobyDoo>(new ScoobyDoo());
    return scoobyDoo;
}

// main \\

int main() {
    auto scooby =std::make_shared<Dog>("Scooby", 2, "scooby snakcs");
    auto kitty = std::make_shared<Cat>("Kitty", 3, "mice");

    PetShelter::AddPet(scooby);
    PetShelter::AddPet(kitty);

    for (auto &pet : PetShelter::FindAll<Cat>()) {
        std::cout << pet << '\n';
    }

    for (auto &pet : PetShelter::FindAll<Dog>()) {
        std::cout << pet << '\n';
    }

    return 0;
}
