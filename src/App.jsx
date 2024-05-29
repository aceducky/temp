import { useEffect, useState } from "react";
import FileDrop from "./FileDrop";
import FileList from "./FileList";
import UploadProvider from "./UploadProvider";
import UrlShortener from "./UrlShortener";
import axios from "axios";
import "./App.css";
import upload_sources from "./upload_sources";

function App() {
  const [files, setFiles] = useState([]);
  const [uploadProvider, setUploadProvider] = useState("file.io");
  const [urlShortener, setUrlShortener] = useState(null);
  const [canUploadFiles, setCanUploadFiles] = useState(false);
  const [isEligible, setIsEligible] = useState(true);
  const[isInFileSizeLimit,setIsInFileSizeLimit]=useState(true)
  const [singleFileOnly, setSingleFileOnly] = useState(true);

  useEffect(() => {
    if (files.length > 0 && uploadProvider) {
      canUploadFiles(true);
    }
  }, [files, uploadProvider, canUploadFiles]);

  return (
    <>
      <UploadProvider
        uploadProvider={uploadProvider}
        setUploadProvider={setUploadProvider}
        setSingleFileOnly={setSingleFileOnly}
      />
      <UrlShortener setUrlShortener={setUrlShortener} />
      <FileDrop
        files={files}
        setFiles={setFiles}
        canUploadFiles={canUploadFiles}
        setCanUploadFiles={setCanUploadFiles}
      />
      <FileList
        files={files}
        setFiles={setFiles}
        uploadProvider={uploadProvider}
        isEligible={isEligible}
        setIsEligible={setIsEligible}
        setCanUploadFiles={setCanUploadFiles}
      />
    </>
  );
}

export default App;
