package nicolas.guillot.hellocpp.core;

public class HelloLib {
  static {
    System.loadLibrary("HelloLib");
  }
  private long mNativeInstance;

  public HelloLib() {
    mNativeInstance = createNativeInstance(this);
    if (mNativeInstance == 0) {
      throw new IllegalStateException();
    }
  }

  public String sayHello(final String name) {
    return sayHello(mNativeInstance, name);
  }

  @Override
  protected void finalize() throws Throwable {
    super.finalize();
    destroy();
  }

  public void destroy() {
    if(mNativeInstance != 0)
      destroy(mNativeInstance);
  }

  private native static long createNativeInstance(final HelloLib helloLib);

  private static native void destroy(final long nativeInstance);

  private native static String sayHello(final long nativeInstance, final String name);
}
