## C Avolitty Associator

#### Author
Avolitty - [https://avolitty.com](https://avolitty.com)

#### Description
In development.

Create secure multidimensional hash tables using C with a fast and unique array associating algorithm.

- Allocates dynamic memory safely with precise bounds
- Compiles with forward-compatible C89 and C++
- Conforms to strict ISO C with -pedantic-errors enabled
- Data with char, double, float, int, long, short and string types supported with all modifiers
- Duplicate keys and values with different data types or modifiers are considered unique
- Each deletion frees memory for the deleted key and value pair without duplicating and resizing arrays
- Efficient without multithreading or processor-specific vectorization
- Fast deletion, hashing, insertion and lookup speeds without relying on compiler optimization
- Hashed keys use 50% less memory than SHA-256 with less probability of collisions
- Incremental memory allocation prevents bloated buffers and memory leaks
- Insertions and updates are merged into a single function with automatic overwriting
- Insertion sort order preserved
- Inserts key/value pairs with redundant storage of unhashed keys
- Inserts key/value pairs without redundant storage of unhashed keys for memory efficiency
- Keys are hashed with a secure base256 variant of Avolitty Hasher
- Keys are only hashed if lengths exceed 32 bytes
- Lookups use flat arrays of keys to represent a path of multidimensional keys in an array
- Memory-safe with defined behavior
- Minified and readable code with single-letter variable names
- Multiple data types supported in a single hash table without using struct or union
- Prints multidimensional hash table contents for parsing data as a multidimensional array
- Reallocates memory efficiently within the scope of each key
- Resizes based on pointer counts instead of bytes allocated to prevent unnecessary calculations and overflows

#### License Tiers
- Free Tier - $0 for evaluation and testing before subscribing to Paid Tier
- Paid Tier - [$1 monthly subscription](https://avolitty.com/subscribe/) for business and personal usage
