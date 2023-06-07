## C Array Associator

#### Description
Create secure multidimensional hash tables using C with a fast and unique array associating algorithm.

- All integral data types supported
- Allocates dynamic memory safely with precise bounds
- Compiles with forward-compatible `C89`
- Conforms to strict ISO C with `-pedantic-errors` enabled
- Duplicate keys and values with different data types or modifiers are considered unique
- Each deletion frees memory for the deleted key and value pair without duplicating and resizing arrays
- Efficient without multithreading or processor-specific vectorization
- Fast deletion, hashing, insertion and lookup speeds without relying on compiler optimization
- Hashed keys use less CPU and memory than SHA-256 with less probability of collisions
- Incremental memory allocation prevents bloated buffers and memory leaks
- Insertions and updates are merged into a single function with automatic overwriting
- Insertion sort order preserved
- Inserts key/value pairs with redundant storage of unhashed keys
- Inserts key/value pairs without redundant storage of unhashed keys for memory efficiency
- Keys are hashed with a secure base256 variant of [C Hasher](https://github.com/frymimori/c-hasher)
- Keys are only hashed if lengths exceed 32 bytes
- Lookups use flat arrays of keys to represent a path of multidimensional keys in an array
- Memory-safe with defined behavior
- Minified and readable code with single-letter variable names
- Multiple data types supported in a single hash table without using `struct` or `union`
- Prints multidimensional hash table contents for parsing data as a multidimensional array
- Reallocates memory efficiently within the scope of each key
- Resizes memory blocks automatically after 10% of key and value pairs deleted
- Resizes memory blocks based on unassigned pointer counts to prevent extra calculations and overflows
- Resizes memory blocks incrementally instead of duplicating entire memory blocks

#### Usage
In development.
