(function(){
  const cfg = window.GSN_ADSENSE || {};
  if (!cfg.client) return;
  if (!/^ca-pub-\d+$/.test(cfg.client)) return;
  if (!document.querySelector('script[data-gsn-adsense]')) {
    const s=document.createElement('script');
    s.async=true; s.crossOrigin='anonymous'; s.dataset.gsnAdsense='1';
    s.src='https://pagead2.googlesyndication.com/pagead/js/adsbygoogle.js?client='+encodeURIComponent(cfg.client);
    document.head.appendChild(s);
  }
  // Auto ads are controlled in the AdSense account. This file only loads the official script
  // after the real publisher ID is configured. No fake publisher ID is shipped.
})();
