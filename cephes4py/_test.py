def test(verbose=True):
    r"""Run tests to verify this package's integrity.

    Parameters
    ----------
    verbose : bool
        ``True`` to show diagnostic. Defaults to ``True``.

    Returns
    -------
    int
        Exit code: ``0`` for success.
    """

    args = []
    if not verbose:
        args += ["--quiet"]

    args += ["--pyargs", __name__.split(".", maxsplit=1)[0]]

    return __import__("pytest").main(args)