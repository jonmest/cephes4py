from cffi import FFI
import numpy as np
from numpy.testing import assert_almost_equal
from scipy.special import bdtr as scipy_btdr, smirnov as scipy_smirnov, jv as scipy_jv, ellipe as scipy_ellipe, fdtr as scipy_fdtr
import numba as nb

import cephes4py

def test_bdtr():
    expected = scipy_btdr(4, 6, 0.3)
    actual = cephes4py.bdtr(4, 6, 0.3)
    assert_almost_equal(actual, expected)


def test_btdr_numba_compatible():
    @nb.njit
    def nb_btdr(k, n, p):
        return cephes4py.bdtr(k, n, p)

    expected = scipy_btdr(4, 6, 0.3)
    actual = nb_btdr(4, 6, 0.3)
    assert_almost_equal(actual, expected)


def test_smirnov():
    n = 5
    p = 0.5
    expected = scipy_smirnov(n, p)
    actual = cephes4py.smirnov(n, p)
    assert_almost_equal(actual, expected)


def test_jv():
    v = 1
    z = 1.0
    expected = scipy_jv(v, z)
    actual = cephes4py.jv(v, z)
    assert_almost_equal(actual, expected)

    # Test v<0
    v = -1
    expected = scipy_jv(v, z)
    actual = cephes4py.jv(v, z)
    assert_almost_equal(actual, expected)


def test_ellipe():
    a = 3.5
    b = 2.1
    e_sq = 1.0 - b**2/a**2
    expected = 4*a*scipy_ellipe(e_sq)
    actual = 4*a*cephes4py.ellpe(e_sq)
    assert_almost_equal(actual, expected)


def test_fdtr():
    expected = scipy_fdtr(1, 2, 1)
    actual = cephes4py.fdtr(1, 2, 1)
    assert_almost_equal(actual, expected)


def test_chbevl():
    array = np.zeros(29, dtype=np.float_)
    array[:] = -8
    cephes4py.chbevl(2, cephes4py.np_from_buf(array), 32)
    cephes4py.chbevl(2, cephes4py.from_buffer("double[]", array), 32)

if __name__ == "__main__":
    test_chbevl()
    test_bdtr()
    test_btdr_numba_compatible()
    test_smirnov()    
    test_jv()
    test_ellipe()
    test_fdtr()

