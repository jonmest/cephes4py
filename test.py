from numpy.testing import assert_almost_equal
from scipy.special import bdtr as scipy_btdr
import numba as nb

import pycephes

def test_bdtr():
    expected = scipy_btdr(4, 6, 0.3)
    actual = pycephes.bdtr(4, 6, 10.3)
    assert_almost_equal(actual, expected)

def test_btdr_numba_compatible():
    @nb.njit
    def nb_btdr(k, n, p):
        return pycephes.bdtr(k, n, p)

    expected = scipy_btdr(4, 6, 0.3)
    actual = nb_btdr(4, 6, 0.3)
    assert_almost_equal(actual, expected)

if __name__ == "__main__":
    test_bdtr()
    #test_btdr_numba_compatible()
    
