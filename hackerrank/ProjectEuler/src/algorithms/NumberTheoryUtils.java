package algorithms;

import utils.Triplet;

public class NumberTheoryUtils {

    // Return triplet [d, a, b] such that d = gcd(p, q), ap + bq = d
    public static Triplet<Long, Long, Long> gcdExtended(long p, long q) {
        if (q == 0)
            return new Triplet<>(p, 1L, 0L );
        Triplet<Long, Long, Long> v = gcdExtended(q, p % q);
        long d = v.first;
        long a = v.third;
        long b = v.second - (p / q) * v.third;
        return new Triplet<>(d, a, b);
    }
}
