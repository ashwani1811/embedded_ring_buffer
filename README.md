# Embedded Ring Buffer & CI/CD Pipeline

A lightweight, thread-safe (or interrupt-safe) ring buffer implementation in C, complete with host unit tests, a cross-platform Makefile, static analysis, and an automated GitHub Actions CI/CD pipeline.

---

## Project Structure

```text
├── .github/
│   └── workflows/
│       └── ci.yml        # GitHub Actions CI pipeline configuration
├── src/
│   ├── ring_buffer.c     # Ring buffer implementation source code
│   └── ring_buffer.h     # Ring buffer header file
├── tests/
│   └── test_ring_buffer.c# Test cases and unit test runner
├── Makefile              # Cross-platform build script (Windows / Linux)
└── README.md             # Project documentation
