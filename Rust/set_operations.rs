#[derive(Clone)]
pub struct Set<T: PartialEq + Clone> {
    items: Vec<T>,
}

impl<T: PartialEq + Clone> Set<T> {
    /// Creates an empty set
    pub fn new() -> Self {
        Set { items: vec![] }
    }

    /// Inserts `item` into this set. If `item` is already in the set, this does nothing
    pub fn insert(&mut self, item: T) {
        if !self.contains(&item) {
            self.items.push(item);
        }
    }

    /// Removes `item` from this set, if `item` is contained in the set. If it is not, this does nothing.
    pub fn remove(&mut self, item: &T) {
        if let Some(idx) = self.items.iter().position(|x| x == item) {
            self.items.remove(idx);
        }
    }

    /// Checks if this set contains `item`.
    pub fn contains(&self, item: &T) -> bool {
        self.items.contains(item)
    }

    /// Finds the interesection of this set and the other, returning a new set.
    /// Letting `self` be set `A` and `other` be set `B`, calculates the set of all elements which are either in set `A` or `B`.
    pub fn union(self, other: Self) -> Self {
        let mut new_set = self.clone();
        for item in other.items {
            new_set.insert(item);
        }
        new_set
    }

    /// Finds the intersection of this set and the other, returning a new set.
    /// Letting `self` be set `A` and `other` be set `B`, calculates the set of all elements which are in both `A` and `B`.    
    pub fn intersection(self, other: Self) -> Self {
        let mut new_set = Set::new();
        for item in self.items.into_iter().filter(|x| other.contains(x)) {
            new_set.insert(item);
        }
        new_set
    }

    /// Takes the difference between this set and other, returning a new set.
    /// Letting `self` be set `A`, and `other` be set `B`, calculates `A - B`, the set of all elements in A which are not in B.
    pub fn difference(self, other: Self) -> Self {
        let mut new_set = self.clone();
        for item in other.items {
            new_set.remove(&item)
        }
        new_set
    }

    /// Takes the symmetric difference between this set and the other, returning a new set.
    /// Letting `self` be set `A` and `other` be set `B`, calculates the set of all elements which are in either `A` or `B`, but not both.
    pub fn sym_difference(self, other: Self) -> Self {
        let mut new_set = self.clone().union(other.clone());
        let intersetction = self.intersection(other);
        for item in intersetction.items {
            new_set.remove(&item)
        }
        new_set
    }
}
