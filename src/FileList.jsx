
import { useState } from "react";
import upload_sources from "./upload_sources";
/* eslint-disable react/prop-types */
export default function FileList({ files, setFiles, uploadProvider,setCanUploadFiles }) {
  const [isEligible, sconditionetIsEligible] = useState(true);
  function removeFile(file) {
    setFiles(files.filter((f) => f.name !== file.name));
  }
  function getFileSizeInMb(file) {
    return (file.size / 1024/1024).toFixed(2);
  }
  function getFileSizeInKb(file) {
    return (file.size / 1024).toFixed(2)
  }
  return (
    <div id="files-list">
      <h2>{files.length > 0 ? `Files` : "No files"}</h2>
      <div>
        {files.map((file) => (
          <div className="file-card" key={file.name}>
            <span>{file.name}</span>
            <span>
              {(getFileSizeInMb(file)>upload_sources[uploadProvider].maxFileSizeInMb)? <p>File size exceeded </p>:<p></p>}
            </span>
            {
              <button
                id="remove-file-btn"
                onClick={() => removeFile(file)}
                disabled={!isEligible}
              >
                Remove
              </button>
            }
          </div>
        ))}
      </div>
    </div>
  );
}
